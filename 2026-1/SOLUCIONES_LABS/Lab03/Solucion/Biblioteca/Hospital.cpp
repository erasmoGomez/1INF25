//
// Created by Daniel Sanchez on 6/05/26.
//

#include "Hospital.h"

#include <fstream>
#include <iostream>

char *read_string(std::ifstream &arch, char d = ',') {
    constexpr int BUFF_SIZE = 64;
    char buffer[BUFF_SIZE]{};
    arch.getline(buffer, BUFF_SIZE, d);
    char *str = new char[strlen(buffer) + 1];
    strcpy(str, buffer);
    return str;
}

int read_date(std::ifstream &arch) {
    char c;
    int year, month, day;
    arch >> year >> c >> month >> c >> day >> c;
    return year * 10000 + month * 100 + day;
}

int read_time(std::ifstream &arch) {
    char c;
    int hour, minute;
    arch >> hour >> c >> minute >> c;
    return hour * 60 + minute;
}

bool readPaciente(std::ifstream &arch, void *&paciente) {
    int id;
    arch >> id;
    if (arch.eof()) {
        return false;
    }
    char c, genero;
    arch >> c;
    char *nombre = read_string(arch, ',');
    int edad;
    arch >> edad >> c >> genero;
    arch >> std::ws;
    void **paciente_arr = new void *[PACIENTE_COUNT]{};
    paciente_arr[PACIENTE_ID] = new int(id);
    paciente_arr[PACIENTE_NAME] = nombre;
    paciente_arr[PACIENTE_AGE] = new int(edad);
    paciente_arr[PACIENTE_GENDER] = new char(genero);
    paciente_arr[PACIENTE_VISITS] = nullptr;
    paciente_arr[PACIENTE_COST] = new double(0.0);
    paciente = paciente_arr;
    return true;
}

void cargarPacientes(const char *arch_name, void *&pacientes) {
    std::ifstream file;
    file.open(arch_name, std::ios::in);
    if (not file.is_open()) {
        std::cerr << "Error opening file " << arch_name << "\n";
    }

    // Memoria exacta para los pacientes
    constexpr int AUX_SIZE = 128;
    void **pacientes_aux = new void *[AUX_SIZE]{};
    int n_pacientes = 0;
    while (true) {
        if (!readPaciente(file, pacientes_aux[n_pacientes])) break;
        n_pacientes++;
    }
    file.close();

    // Recortar memoria para los pacientes
    void **pacientes_arr = new void *[n_pacientes + 1]{};
    for (int i = 0; i < n_pacientes; i++) {
        pacientes_arr[i] = pacientes_aux[i];
    }
    pacientes_arr[n_pacientes] = nullptr;
    delete[] pacientes_aux;
    pacientes = pacientes_arr;
}

bool readVisita(std::ifstream &arch, int &fecha, int &hora, int &idPaciente,
                double &costo) {
    fecha = read_date(arch);
    if (arch.eof()) {
        return false;
    }
    hora = read_time(arch);
    char c;
    arch >> idPaciente >> c >> costo;
    arch >> std::ws;
    return true;
}

int buscarPaciente(void **pacientes_arr, int idPaciente) {
    for (int i = 0; pacientes_arr[i] != nullptr; i++) {
        void **paciente_arr = (void **) pacientes_arr[i];
        int *id_ptr = (int *) paciente_arr[PACIENTE_ID];
        if (*id_ptr == idPaciente) {
            return i;
        }
    }
    return -1;
}

void guardarVisita(void *&visitas, int fecha, int hora, double costo) {
    // Memoria exacta para las visitas
    if (visitas == nullptr) {
        constexpr int MAX_VISITAS = 128;
        visitas = new void *[MAX_VISITAS]{};
    }
    void **visitas_arr = (void **) visitas;
    // Acumular costo si visita con misma fecha y hora ya existe
    int i = 0;
    for (; visitas_arr[i] != nullptr; i++) {
        void **visita_arr = (void **) visitas_arr[i];
        int *date = (int *) visita_arr[VISIT_DATE];
        int *time = (int *) visita_arr[VISIT_TIME];
        if (*date == fecha && *time == hora) {
            double *cost = (double *) visita_arr[VISIT_COST];
            *cost += costo;
        }
    }
    void **new_visita_arr = new void *[VISIT_COUNT]{};
    new_visita_arr[VISIT_DATE] = new int(fecha);
    new_visita_arr[VISIT_TIME] = new int(hora);
    new_visita_arr[VISIT_COST] = new double(costo);
    visitas_arr[i] = new_visita_arr;
}

void acumularCosto(void **paciente_arr, double costo) {
    double *costoTotal = (double *) paciente_arr[PACIENTE_COST];
    *costoTotal += costo;
}

int countElements(void **arr) {
    int i = 0;
    while (arr[i] != nullptr) {
        i++;
    }
    return i;
}

void cargarVisitas(const char *arch_name, void *pacientes) {
    std::ifstream file;
    file.open(arch_name, std::ios::in);
    if (not file.is_open()) {
        std::cerr << "Error opening file " << arch_name << "\n";
    }
    void **pacientes_arr = (void **) pacientes;
    int n_fechas = 0;
    while (true) {
        int fecha, hora, idPaciente;
        double costo;
        if (!readVisita(file, fecha, hora, idPaciente, costo)) break;
        n_fechas += 1;
        int pos = buscarPaciente(pacientes_arr, idPaciente);
        if (pos != -1) {
            void **paciente_arr = (void **) pacientes_arr[pos];
            guardarVisita(paciente_arr[PACIENTE_VISITS], fecha, hora, costo);
            acumularCosto(paciente_arr, costo);
        }
    }
    file.close();

    // Recortar memoria de visitas
    for (int i = 0; pacientes_arr[i] != nullptr; i++) {
        void **paciente_arr = (void **) pacientes_arr[i];
        void **visits_arr = (void **) paciente_arr[PACIENTE_VISITS];
        if (visits_arr == nullptr) continue;
        int n_visits = countElements(visits_arr);
        void **visits_arr_aux = new void *[n_visits + 1]{};
        for (int j = 0; j < n_visits; j++) {
            visits_arr_aux[j] = visits_arr[j];
        }
        delete[] visits_arr;
        paciente_arr[PACIENTE_VISITS] = visits_arr_aux;
    }
}

void print_separator(std::ofstream &arch, char s, int n) {
    for (int i = 0; i < n; i++) {
        arch << s;
    }
    arch << std::endl;
}

void generarReporte(const char *arch_name, void *pacientes) {
    std::ofstream file;
    file.open(arch_name, std::ios::out);
    if (not file.is_open()) {
        std::cerr << "Error opening file " << arch_name << "\n";
    }

    constexpr int MARGIN = 80;
    print_separator(file, '=', MARGIN);
    file << std::setw(48) << std::right << "REPORTE DEL SISTEMA DE URGENCIAS" <<
            std::endl;
    print_separator(file, '=', MARGIN);

    print_separator(file, '-', MARGIN);
    file <<
            "   ID         NOMBRE         EDAD    GENERO      VISITAS      TOTAL (S/)"
            << std::endl;
    print_separator(file, '-', MARGIN);
    void **pacientes_arr = (void **) pacientes;
    for (int i = 0; pacientes_arr[i] != nullptr; i++) {
        void **paciente_arr = (void **) pacientes_arr[i];
        int *id = (int *) paciente_arr[PACIENTE_ID];
        char *name = (char *) paciente_arr[PACIENTE_NAME];
        int *age = (int *) paciente_arr[PACIENTE_AGE];
        char *gender = (char *) paciente_arr[PACIENTE_GENDER];
        void **visits = (void **) paciente_arr[PACIENTE_VISITS];
        double *cost = (double *) paciente_arr[PACIENTE_COST];
        file << std::setw(12) << std::left << *id;
        file << std::setw(16) << std::left << name;
        file << std::setw(6) << std::right << *age;
        file << std::setw(6) << std::right << gender;
        if (visits == nullptr) {
            file << std::setw(16) << std::right << "<NONE>";
        } else {
            int n_visits = countElements(visits);
            file << std::setw(16) << std::right << n_visits;
        }
        file << std::fixed << std::setprecision(2) << std::setw(12) <<
                std::right
                << *cost;
        file << std::endl;
    }
    file.close();
}

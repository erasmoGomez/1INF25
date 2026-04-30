//
// Created by Daniel Sanchez on 23/04/26.
//

#include "ER.h"

#include <fstream>
#include <iostream>

int leerFecha(std::ifstream &arch) {
    char c;
    int dia, mes, ano;
    arch >> dia;
    if (arch.eof()) return -1;
    arch >> c >> mes >> c >> ano >> c;
    return 10000 * ano + 100 * mes + dia;
}

int leerHora(std::ifstream &arch) {
    char c;
    int hora, minuto, segundo;
    arch >> hora >> c >> minuto >> c >> segundo >> c;
    return 3600 * hora + 60 * minuto + segundo;
}

char *leerString(std::ifstream &arch, char del = '\n') {
    constexpr int BUFFER_SIZE = 64;
    char buffer[BUFFER_SIZE];
    arch.getline(buffer, BUFFER_SIZE, del);
    char *res = new char [strlen(buffer) + 1];
    strcpy(res, buffer);
    return res;
}

bool leerRegistro(std::ifstream &arch, int &fecha, char **&texto, int *&enteros, float *&flotantes) {
    fecha = leerFecha(arch);
    if (fecha == -1) return false;

    char c;
    char *idPaciente = leerString(arch, ',');
    char *nombrePaciente = leerString(arch, ',');
    int horaIngreso = leerHora(arch);
    float temperatura;
    arch >> temperatura >> c;
    int presionSistolica, presionDiastolica;
    arch >> presionSistolica >> c >> presionDiastolica >> c;
    int horaAlta = leerHora(arch);
    char *especialidad = leerString(arch, '\n');
    arch >> std::ws;

    texto = new char *[3];
    texto[0] = idPaciente;
    texto[1] = nombrePaciente;
    texto[2] = especialidad;

    enteros = new int [5];
    enteros[0] = horaIngreso;
    enteros[1] = horaAlta;
    enteros[2] = presionSistolica;
    enteros[3] = presionDiastolica;
    enteros[4] = 0; // Tiempo de Atencion

    flotantes = new float[2]{};
    flotantes[0] = temperatura;
    flotantes[1] = 0.0; // Costo

    return true;
}

int buscarFecha(int const *fechas, int n_fechas, int fecha) {
    for (int i = 0; i < n_fechas; i++) {
        if (fechas[i] == fecha) {
            return i;
        }
    }
    return -1;
}

void resize(int &cap, int n, char ***&registroTexto, int **&registroEnteros,
            float **&registroFlotantes) {
    constexpr int RESIZE_SIZE = 5;
    cap += RESIZE_SIZE;

    char ***registroTexto_aux = new char **[cap]{};
    int **registroEnteros_aux = new int *[cap]{};
    float **registroFlotantes_aux = new float *[cap]{};
    if (n > 0) {
        for (int i = 0; i < n; i++) {
            registroTexto_aux[i] = registroTexto[i];
            registroEnteros_aux[i] = registroEnteros[i];
            registroFlotantes_aux[i] = registroFlotantes[i];
        }
        delete [] registroTexto;
        delete [] registroEnteros;
        delete [] registroFlotantes;
    }
    registroTexto = registroTexto_aux;
    registroEnteros = registroEnteros_aux;
    registroFlotantes = registroFlotantes_aux;
}

int obtenerPosicionOrdenada(int fecha, int n_registros, int *fechas_aux, char ****datosDeTexto_aux,
                            int ***datosEnteros_aux, float ***datosDePuntoFlotante_aux, int *capacities, int *sizes) {
    // Agregar al final?
    if (n_registros == 0 || fecha > fechas_aux[n_registros - 1]) {
        return n_registros;
    }

    // Buscar la posicion correcta para insertar
    for (int i = 0; i < n_registros; i++) {
        if (fecha == fechas_aux[i]) {
            return i; // Ya existe
        }
        if (fecha < fechas_aux[i]) {
            for (int j = n_registros; j > i; j--) {
                fechas_aux[j] = fechas_aux[j - 1];
                datosDeTexto_aux[j] = datosDeTexto_aux[j - 1];
                datosEnteros_aux[j] = datosEnteros_aux[j - 1];
                datosDePuntoFlotante_aux[j] = datosDePuntoFlotante_aux[j - 1];
                capacities[j] = capacities[j - 1];
                sizes[j] = sizes[j - 1];

                fechas_aux[j - 1] = 0;
                datosDeTexto_aux[j - 1] = nullptr;
                datosEnteros_aux[j - 1] = nullptr;
                datosDePuntoFlotante_aux[j - 1] = nullptr;
                capacities[j - 1] = 0;
                sizes[j - 1] = 0;
            }
            return i;
        }
    }
    return n_registros; // Inserta al final
}

void ingresarRegistro(int &cap, int &n, char ***&registrosTexto, char **texto, int **&registrosEnteros, int *enteros,
                      float **&registrosFlotantes, float *flotantes) {
    if (cap == n) {
        resize(cap, n, registrosTexto, registrosEnteros, registrosFlotantes);
    }
    registrosTexto[n] = texto;
    registrosEnteros[n] = enteros;
    registrosFlotantes[n] = flotantes;
    n += 1;
}

void cargarInformacion(const char *nombreDelArchivo, int *&fechas, char ****&datosDeTexto, int ***&datosEnteros,
                       float ***&datosDePuntoFlotante) {
    std::ifstream archivo;
    archivo.open(nombreDelArchivo, std::ifstream::in);
    if (!archivo.is_open()) {
        std::cerr << "Error al abrir el archivo " << nombreDelArchivo << std::endl;
        exit(1);
    }

    constexpr int AUX_SIZE = 2048;
    int fechas_aux[AUX_SIZE]{};
    char ***datosDeTexto_aux[AUX_SIZE]{};
    int **datosEnteros_aux[AUX_SIZE]{};
    float **datosDePuntoFlotante_aux[AUX_SIZE]{};
    int capacities[AUX_SIZE]{};
    int sizes[AUX_SIZE]{};

    int n_registros = 0;
    while (true) {
        int fecha = -1;
        char **texto;
        int *enteros;
        float *flotantes;
        if (!leerRegistro(archivo, fecha, texto, enteros, flotantes)) break;

        int pos = obtenerPosicionOrdenada(fecha, n_registros, fechas_aux, datosDeTexto_aux, datosEnteros_aux,
                                          datosDePuntoFlotante_aux, capacities, sizes);
        fechas_aux[pos] = fecha;
        ingresarRegistro(capacities[pos], sizes[pos], datosDeTexto_aux[pos], texto, datosEnteros_aux[pos], enteros,
                         datosDePuntoFlotante_aux[pos],
                         flotantes);
        n_registros++;
        //std::cout << fecha << ',' << texto[0] << ',' << texto[2] << std::endl;
    }

    fechas = new int[n_registros + 1]{};
    datosDeTexto = new char ***[n_registros + 1]{};
    datosEnteros = new int **[n_registros + 1]{};
    datosDePuntoFlotante = new float **[n_registros + 1]{};
    for (int i = 0; i < n_registros; i++) {
        fechas[i] = fechas_aux[i];
        datosDeTexto[i] = datosDeTexto_aux[i];
        datosEnteros[i] = datosEnteros_aux[i];
        datosDePuntoFlotante[i] = datosDePuntoFlotante_aux[i];
    }

    archivo.close();
}

void completarInformacion(int *fechas, char ****datosDeTexto, int ***datosEnteros, float ***datosDePuntoFlotante) {
    constexpr float COSTO_POR_HORA = 100.00;
    constexpr float fraction = 1 / 3600.;

    for (int i = 0; fechas[i] > 0; i++) {
        int **registrosEnteros = datosEnteros[i];
        float **registrosFlotantes = datosDePuntoFlotante[i];
        for (int j = 0; registrosEnteros[j] != nullptr; j++) {
            int *registroEntero = registrosEnteros[j];
            float *registroFlotante = registrosFlotantes[j];

            int ingreso = registroEntero[0];
            int alta = registroEntero[1];
            if (alta < ingreso) {
                alta += 24 * 3600; // Se paso al dia siguiente
            }
            int tiempoAtencion = alta - ingreso;
            registroEntero[4] = tiempoAtencion;

            registroFlotante[1] = COSTO_POR_HORA * (tiempoAtencion * fraction);
        }
    }
}

void print_delimiter(std::ofstream &arch, int n, char c = '=') {
    for (int i = 0; i < n; i++) {
        arch << c;
    }
    arch << std::endl;
}

std::ofstream &print_fecha(std::ofstream &arch, int fecha) {
    int dia, mes, ano;
    ano = (fecha / 10000);
    mes = (fecha % 10000) / 100;
    dia = (fecha % 100);
    arch << dia << '/' << mes << '/' << ano;
    return arch;
}

std::ofstream &print_tiempo(std::ofstream &arch, int tiempo) {
    int hora, minuto, segundo;
    hora = (tiempo / 3600);
    minuto = (tiempo % 3600) / 60;
    segundo = (tiempo % 60);
    arch << std::right << std::setfill('0') << std::setw(2) << hora << ':';
    arch << std::right << std::setfill('0') << std::setw(2) << minuto << ':';
    arch << std::right << std::setfill('0') << std::setw(2) << segundo;
    arch << std::setfill(' ') << "    ";
    return arch;
}

std::ofstream &print_presion(std::ofstream &arch, int sistolica, int diastolica) {
    arch << std::right << std::setw(15) << sistolica << '/';
    arch << std::left << std::setw(8) << diastolica;
    return arch;
}

void reporteDeAtenciones(const char *nombreDelArchivo, int *fechas, char ****datosDeTexto, int ***datosEnteros,
                         float ***datosDePuntoFlotante) {
    std::ofstream arch;
    arch.open(nombreDelArchivo, std::ios::out);
    if (!arch.is_open()) {
        std::cerr << "Error al abrir el archivo " << nombreDelArchivo << std::endl;
        exit(1);
    }

    print_delimiter(arch, 120, '=');
    arch << "                                       CLINICA DE URGENCIAS PROG2_SALUD" << std::endl;
    arch << "                                          REGISTRO DE LAS ATENCIONES" << std::endl;
    print_delimiter(arch, 120, '=');

    int i = 0;
    for (i = 0; fechas[i] > 0; i++) {
        arch << "FECHA: ";
        print_fecha(arch, fechas[i]) << std::endl;
        arch << "REGISTRO DE ATENCIONES:" << std::endl;
        print_delimiter(arch, 120, '-');

        char ***registrosTextos = datosDeTexto[i];
        int **registrosEnteros = datosEnteros[i];
        float **registrosFlotantes = datosDePuntoFlotante[i];
        arch <<
                "ID            NOMBRE          INGRESO       ALTA      DURACION     COSTO    TEMPERATURA    PRESION ARTERIAL       ESPECIALIDAD"
                << std::endl;
        for (int j = 0; registrosEnteros[j] != nullptr; j++) {
            char **registroTexto = registrosTextos[j];
            int *registroEntero = registrosEnteros[j];
            float *registroFlotante = registrosFlotantes[j];

            arch << std::left << std::setw(14) << registroTexto[0];
            arch << std::left << std::setw(16) << registroTexto[1];
            print_tiempo(arch, registroEntero[0]);
            print_tiempo(arch, registroEntero[1]);
            print_tiempo(arch, registroEntero[4]);
            arch << std::setw(6) << std::right << std::fixed << std::setprecision(2) << registroFlotante[1];
            arch << std::setw(12) << std::right << std::fixed << std::setprecision(2) << registroFlotante[0];
            print_presion(arch, registroEntero[2], registroEntero[3]);
            arch << std::right << std::setw(18) << registroTexto[2];
            arch << std::endl;
        }
        print_delimiter(arch, 120, '=');
    }
    std::cout << "Numero de fechas distintas: " << i << std::endl;

    arch.close();
}

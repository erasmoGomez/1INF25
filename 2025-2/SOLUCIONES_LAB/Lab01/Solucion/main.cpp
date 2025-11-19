#include "Estructuras.h"
#include "Funciones.h"

#include <fstream>
#include <iostream>

void leer_alumnos(struct Alumnos *alumnos) {
    std::ifstream arch_alumnos;
    arch_alumnos.open("Alumnos.csv", std::ios::in);
    if (not arch_alumnos.is_open()) {
        std::cerr << "Error al abrir el archivo Alumnos.csv" << std::endl;
        exit(1);
    }

    int numalumnos = 0;
    while (arch_alumnos >> alumnos[numalumnos]) {
        numalumnos += 1;
    }
    alumnos[numalumnos].codigo = 0;
    arch_alumnos.close();
}

void leer_cursos(struct Cursos *cursos) {
    std::ifstream arch_cursos;
    arch_cursos.open("Cursos.csv", std::ios::in);
    if (not arch_cursos.is_open()) {
        std::cerr << "Error al abrir el archivo Cursos.csv" << std::endl;
        exit(1);
    }

    int numcursos = 0;
    while (arch_cursos >> cursos[numcursos]) {
        numcursos += 1;
    }
    cursos[numcursos].codigo = nullptr;
    arch_cursos.close();
}

int buscar_curso(struct Cursos *cursos, const char *codigocurso) {
    for (int i = 0; cursos[i].codigo != nullptr; i += 1) {
        if (cursos[i] > codigocurso) {
            return i;
        }
    }
    return -1;
}

int buscar_alumno(struct Alumnos *alumnos, int codigoalumno) {
    for (int i = 0; alumnos[i].codigo != 0; i += 1) {
        if (alumnos[i] > codigoalumno) {
            return i;
        }
    }
    return -1;
}

void leer_matriculas(struct Alumnos *alumnos, struct Cursos *cursos) {
    std::ifstream arch_matricula;
    arch_matricula.open("Matricula.csv", std::ios::in);
    if (not arch_matricula.is_open()) {
        std::cerr << "Error al abrir el archivo Matricula.csv" << std::endl;
        exit(1);
    }

    while (true) {
        constexpr int BUFFER_SIZE = 8;
        char codigocurso[BUFFER_SIZE];
        arch_matricula.getline(codigocurso, BUFFER_SIZE, ',');
        if (arch_matricula.eof()) {
            break;
        }
        int codigoalumno;
        arch_matricula >> codigoalumno;
        arch_matricula >> std::ws;

        int curso_i = buscar_curso(cursos, codigocurso);
        int alumno_i = buscar_alumno(alumnos, codigoalumno);
        if (curso_i != -1 and alumno_i != -1) {
            cursos[curso_i] += alumnos[alumno_i];
        }
    }
    arch_matricula.close();
}

void determinar_modalidad(struct Cursos *cursos) {
    for (int i = 0; cursos[i].codigo != nullptr; i += 1) {
        ++cursos[i];
    }
}

void imprimir_reporte(const struct Cursos *cursos) {
    std::ofstream arch;
    arch.open("Reporte.txt", std::ios::out);

    for (int i = 0; cursos[i].codigo != nullptr; i += 1) {
        arch << cursos[i];
    }
}

int main(int argc, char *argv[]) {
    struct Alumnos alumnos[100]{};
    leer_alumnos(alumnos);

    struct Cursos cursos[100]{};
    leer_cursos(cursos);

    leer_matriculas(alumnos, cursos);

    determinar_modalidad(cursos);

    imprimir_reporte(cursos);

    return 0;
}

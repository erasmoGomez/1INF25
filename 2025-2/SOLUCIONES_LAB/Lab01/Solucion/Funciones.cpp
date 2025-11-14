//
// Created by Daniel Sanchez on 5/09/25.
//

#include "Estructuras.h"
#include "Funciones.h"

#include <cstring>
#include <fstream>
#include <iomanip>

// Lectura

bool operator>>(std::ifstream &arch, struct Cursos &curso) {
    constexpr int BUFFER_SIZE = 100;
    char buffer[BUFFER_SIZE];
    arch.getline(buffer, BUFFER_SIZE, ',');
    if (arch.eof()) {
        return false;
    }
    curso.codigo = new char[strlen(buffer) + 1];
    strcpy(curso.codigo, buffer);

    arch.getline(buffer, BUFFER_SIZE, ',');
    curso.nombre = new char[strlen(buffer) + 1];
    strcpy(curso.nombre, buffer);

    char c;
    int codigo_docente;
    arch >> curso.creditos >> c >> codigo_docente >> c;

    arch.getline(buffer, BUFFER_SIZE, '\n');
    curso.docente = new char[strlen(buffer) + 1];
    strcpy(curso.docente, buffer);

    return true;
}

bool operator>>(std::ifstream &arch, struct Alumnos &alumno) {
    constexpr int BUFFER_SIZE = 100;
    char buffer[BUFFER_SIZE];

    char c;
    arch >> alumno.codigo;
    if (arch.eof()) {
        return false;
    }
    arch >> c;

    arch.getline(buffer, BUFFER_SIZE, ',');
    alumno.nombre = new char[strlen(buffer) + 1];
    strcpy(alumno.nombre, buffer);

    arch >> alumno.tipo;
    arch >> std::ws;

    return true;
}

// Operaciones

bool operator>(const struct Alumnos &alumno, const int codigoalumno) {
    return alumno.codigo == codigoalumno;
}

bool operator>(const struct Cursos &curso, const char *codigocurso) {
    return strcmp(curso.codigo, codigocurso) == 0;
}

void operator+=(struct Cursos &curso, const struct Alumnos &alumno) {
    switch (alumno.tipo) {
        case 'P': {
            curso.presencial[curso.numpresencial] = alumno;
            curso.numpresencial += 1;
            break;
        }
        case 'S': {
            curso.semipresencial[curso.numsemipresencial] = alumno;
            curso.numsemipresencial += 1;
            break;
        }
        case 'V': {
            curso.vvirtual[curso.numvirtual] = alumno;
            curso.numvirtual += 1;
            break;
        }
    }
}

int operator<=(const struct Alumnos *alumnos, const struct Alumnos &alumno) {
    for (int i = 0; alumnos[i].codigo != 0; i += 1) {
        if (alumnos[i].codigo == alumno.codigo) {
            return i;
        }
    }
    return -1;
}

int operator>=(const struct Cursos *cursos, const struct Cursos &curso) {
    for (int i = 0; cursos[i].codigo != nullptr; i += 1) {
        if (strcmp(cursos[i].codigo, curso.codigo) == 0) {
            return i;
        }
    }
    return -1;
}

void operator++(struct Cursos &curso) {
    int numalumnos = curso.numsemipresencial + curso.numpresencial + curso.numvirtual;
    double perc = curso.numpresencial / numalumnos * 1.;
    if (perc >= 0.5) {
        char buffer[] = "La clase se dictará en el aula.";
        curso.tipofinal = new char[strlen(buffer) + 1];
        strcpy(curso.tipofinal, buffer);
    } else {
        char buffer[] = "La clase se dictará 100% virtual.";
        curso.tipofinal = new char[strlen(buffer) + 1];
        strcpy(curso.tipofinal, buffer);
    }
}

// Impresión

void operator<<(std::ofstream &arch, const struct Cursos &curso) {
    arch << std::left << std::setw(12) << curso.codigo;
    arch << std::right << curso.nombre << std::endl;
    arch << curso.docente << std::endl;
    arch << "Alumnos presenciales:  " << curso.numpresencial << std::endl;
    arch << "Alumnos semipresencia: " << curso.numsemipresencial << std::endl;
    arch << "Alumnos virtuales:     " << curso.numvirtual << std::endl;
    arch << curso.tipofinal << std::endl;
    for (int i = 0; i < 32; i += 1) {
        arch << '=';
    }
    arch << std::endl;
}

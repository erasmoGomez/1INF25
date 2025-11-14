//
// Created by Daniel Sanchez on 5/09/25.
//

#ifndef SOLUCION_FUNCIONES_H
#define SOLUCION_FUNCIONES_H

#include "Estructuras.h"

#include <fstream>

// Lectura

bool operator>>(std::ifstream &arch, struct Cursos &curso);

bool operator>>(std::ifstream &arch, struct Alumnos &alumno);

// Operaciones

bool operator>(const struct Alumnos &alumno, int codigoalumno);

bool operator>(const struct Cursos &curso, const char *codigocurso);

void operator+=(struct Cursos &curso, const struct Alumnos &alumno);

int operator<=(const struct Alumnos *alumnos, const struct Alumnos &alumno);

int operator>=(const struct Cursos *cursos, const struct Cursos &curso);

void operator++(struct Cursos &curso);

// Impresión

void operator<<(std::ofstream &arch, const struct Cursos &curso);

#endif //SOLUCION_FUNCIONES_H

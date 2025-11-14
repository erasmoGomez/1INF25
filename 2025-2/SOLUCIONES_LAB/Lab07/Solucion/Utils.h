//
// Created by Daniel Sanchez on 7/11/25.
//

#ifndef SOLUCION_UTILS_H
#define SOLUCION_UTILS_H

#include <fstream>

char *my_strdup(const char *s);

int leer_fecha(std::ifstream &arch);

std::ostream &imprimir_fecha(std::ostream &arch, int fecha);

std::ostream &imprimir_sep(std::ostream &arch, int n, char sep);

#endif //SOLUCION_UTILS_H

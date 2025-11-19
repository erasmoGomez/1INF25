//
// Created by Daniel Sanchez on 7/11/25.
//

#include "Utils.h"

#include <fstream>

char *my_strdup(const char *s) {
    char *dup = new char[strlen(s) + 1];
    strcpy(dup, s);
    return dup;
}

int leer_fecha(std::ifstream &arch) {
    char c;
    int dia, mes, anho;
    arch >> anho >> c >> mes >> c >> dia;

    return 10000 * anho + 100 * mes + dia;
}

std::ostream &imprimir_fecha(std::ostream &arch, int fecha) {
    int anho = fecha / 10000;
    int mes = (fecha % 10000) / 100;
    int dia = fecha % 100;
    arch << anho << "/" << std::setw(2) << std::setfill('0') << mes << "/" << std::setw(2) << std::setfill('0') << dia;
    return arch;
}

std::ostream &imprimir_sep(std::ostream &arch, int n, char sep) {
    for (int i = 0; i < n; i++) {
        arch << sep;
    }
    arch << std::endl;
    return arch;
}

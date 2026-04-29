//
// Created by erasmo on 4/29/26.
//

#ifndef LISTASLIGADAS_HELPERS_HPP
#define LISTASLIGADAS_HELPERS_HPP
#include "utils.hpp"

char *leer_cadena(ifstream &input, char del);

void apertura_archivo_entrada(ifstream &input, const char *nombre_archivo);

void apertura_archivo_salida(ofstream &output, const char *nombre_archivo);
#endif //LISTASLIGADAS_HELPERS_HPP

//
// Created by Erasmo on 11/09/25.
//

#ifndef LECTURA_TOPES_FUNCIONES_HPP
#define LECTURA_TOPES_FUNCIONES_HPP

#include "Utils.hpp"

char *read_str(ifstream &archivo, char separador);

void cargar_apodos(ifstream &input, char **&apodos);

void leer_datos(ifstream &input, char **&apodos);

#endif //LECTURA_TOPES_FUNCIONES_HPP

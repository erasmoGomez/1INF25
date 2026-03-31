//
// Created by hecto on 8/19/2025.
//

#include "Funciones.hpp"

int suma(int a, int b) {
    return a + b;
}

char *leer_cadena(char del) {
    char *cadena, buffer[50];
    cin.getline(buffer, 50, del);
    cadena = new char[strlen(buffer) + 1];
    strcpy(cadena, buffer);
    return cadena;
}

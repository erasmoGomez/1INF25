#include "Comunes.h"
#include <cstring>

char *mi_strdup(char *cadena) {
    if (cadena==nullptr)
        return nullptr;
    char *resultado = new char[strlen(cadena) + 1];
    strcpy(resultado, cadena);
    return resultado;
}

void liberar_cadena(char *&cadena) {
    if (cadena != nullptr) {
        delete cadena;
        cadena = nullptr;
    }
}
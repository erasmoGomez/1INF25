//
// Created by erasmo on 4/29/26.
//

#include "Helpers.hpp"

char *leer_cadena(ifstream &input, char del) {
    char buffer[60];
    input.getline(buffer, 60, del);
    if (input.eof()) return nullptr;
    char *cad = new char[strlen(buffer) + 1];
    strcpy(cad, buffer);
    return cad;
}

void apertura_archivo_entrada(ifstream &input, const char *nombre_archivo) {
    input.open(nombre_archivo, ios::in);
    if (not input.is_open()) {
        cout << "Error al abrir el archivo " << nombre_archivo << endl;
        exit(1);
    }
}

void apertura_archivo_salida(ofstream &output, const char *nombre_archivo) {
    output.open(nombre_archivo, ios::out);
    if (not output.is_open()) {
        cout << "Error al abrir el archivo " << nombre_archivo << endl;
        exit(1);
    }
}

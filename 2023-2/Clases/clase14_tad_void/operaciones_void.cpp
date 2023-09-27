/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "operaciones_void.hpp"

enum registro_lista {
    CODIGO, NOMBRE, SUELDO
};

void *leer_registro(ifstream &input) {
    int *codigo, cod;
    double *sueldo, sue;
    char* nombre, buffer[150];
    void **registro;
    input>>cod;
    if (input.eof())return nullptr;
    input.get();
    input.getline(buffer, 150, ',');
    input>>sue;
    input.get();
    codigo = new int;
    sueldo = new double;
    nombre = new char[strlen(buffer) + 1];
    *codigo = cod;
    *sueldo = sue;
    strcpy(nombre, buffer);
    registro = new void*[3];
    registro[CODIGO] = codigo;
    registro[SUELDO] = sueldo;
    registro[NOMBRE] = nombre;
    return registro;
}

int cmp_registros_nombre(const void *a, const void*b) {
    void **reg_a = (void**) a, **reg_b = (void**) b;
    char *nombre_a = (char*) reg_a[NOMBRE];
    char *nombre_b = (char*) reg_b[NOMBRE];
    return strcmp(nombre_a, nombre_b);
}

void imprimir_registro(void* _registro, ofstream &output) {
    void**registro = (void**) _registro;
    int *codigo = (int*) registro[CODIGO];
    double *sueldo = (double*) registro[SUELDO];
    char *nombre = (char*) registro[NOMBRE];

    output.precision(2);
    output << fixed;
    output << left << setw(10) << *codigo;
    output << setw(50) << nombre;
    output << right << setw(10) << *sueldo << endl;
}

void eliminar_registro(void*_registro) {
    void **registro = (void**) _registro;
    int *codigo = (int*) registro[CODIGO];
    double* sueldo = (double*) registro[SUELDO];
    char* nombre = (char*) registro[NOMBRE];

    delete codigo;
    delete sueldo;
    delete nombre;
    delete registro;
}
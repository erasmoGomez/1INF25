/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "ListaEmpleados.hpp"

void *lee_empleado(ifstream &input) {
    int codigo;
    double sueldo;
    // 378708,SAENZ ARANDA WILMER,23455.6
    input >> codigo;
    if (input.eof()) return nullptr;
    input.get();
    char *cad = leer_cadena(input, ',');
    input >> sueldo;
    int *ptr_cod = new int;
    auto *ptr_sueldo = new double;
    *ptr_cod = codigo;
    *ptr_sueldo = sueldo;
    void **empleado = new void *[3];
    empleado[CODIGO] = ptr_cod;
    empleado[NOMBRE] = cad;
    empleado[SUELDO] = ptr_sueldo;
    return empleado;
}

int compara_empleado_nombre(const void *e1, const void *e2) {
    void **reg1 = (void **) e1, **reg2 = (void **) e2;
    char *nombre1 = (char *) reg1[NOMBRE], *nombre2 = (char *) reg2[NOMBRE];
    return strcmp(nombre1, nombre2) > 0;
}

int compara_empleado_codigo(const void *e1, const void *e2) {
    void **reg1 = (void **) e1, **reg2 = (void **) e2;
    int *codigo1 = (int *) reg1[CODIGO], *codigo2 = (int *) reg2[CODIGO];
    return *codigo1 - *codigo2;
}

void imprime_empleado(void *empleado, ofstream& output) {
    void **registro = (void **) empleado;
    int *codigo = (int *) registro[CODIGO];
    char *nombre = (char *) registro[NOMBRE];
    auto *sueldo = (double *) registro[SUELDO];
    output.precision(2);
    output << fixed;
    output << setw(10) << *codigo << "   " << left << setw(50) << nombre << right << setw(10) << *sueldo << endl;
}

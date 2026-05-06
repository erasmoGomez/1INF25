//
// Created by erasmo on 5/5/26.
//

#include "ListaConEnteros.hpp"

void *leenumeros(ifstream &arch) {
    void **dato = new void *[1]{};
    int *num = new int;
    arch >> *num;
    if (arch.eof())return nullptr;
    dato[0] = num; // Dereferencia o pos inicial
    return dato;
}

void *leeregnumeros(ifstream &arch) {
    void **dato = new void *[2]{};

    int *num, *num2;
    num2 = new int;
    num = new int;

    arch >> *num;
    if (arch.eof())return nullptr;
    arch >> *num2;

    dato[0] = num;
    dato[1] = num2;

    return dato;
}

// int compruebanumero(const void *clave, const void *dato) {

bool compruebanumero(void *clave, void *dato) {
    void **dat = (void **) clave;
    int *numKey = (int *) dat[0];
    int *num = (int *) dato;
    return *numKey == *num;
}

void imprimenumeros(ofstream &arch, void *d, void *arr) {
    void **dato = (void **) d;
    void **arreglo = (void **) arr;
    int *numero, pos = 0, *num;
    numero = (int *) dato[0];
    arch << *numero << endl;
    while (arreglo[pos]) {
        num = (int *) arreglo[pos];
        arch << *num << "  ";
        pos++;
    }
    arch << endl << endl;
}

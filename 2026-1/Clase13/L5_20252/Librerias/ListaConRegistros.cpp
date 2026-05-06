//
// Created by erasmo on 5/5/26.
//
#include "ListaConRegistros.hpp"

char *leeCadena(ifstream &arch, char del) {
    char *texto, buffer[100]{};
    arch.getline(buffer, 100, del);
    if (arch.eof())return nullptr;
    texto = new char[strlen(buffer) + 1]{};
    strcpy(texto, buffer);
    return texto;
}

void insertaDato(void *&d, char *cod, char *nom, char *veh) {
    void **dato = new void *[3]{};
    dato[0] = cod;
    dato[1] = nom;
    dato[2] = veh;
    d = dato;
}

void *leeregistros(ifstream &arch) {
    char *cod, *nom, *vehiculo;
    void *dato;
    cod = leeCadena(arch, ',');
    if (arch.eof())return nullptr;
    nom = leeCadena(arch, ',');
    vehiculo = leeCadena(arch, '\n');
    insertaDato(dato, cod, nom, vehiculo);
    return dato;
}

void *guardaDemasDatos(int *dni, int *cant, char *plato) {
    void **datos = new void *[3]{};
    datos[0] = dni;
    datos[1] = cant;
    datos[2] = plato;
    return datos;
}

void *leeordenes(ifstream &arch) {
    void **dato = new void *[2]{};
    int *dni = new int, *cant = new int;
    char *plato, *codRep, c;
    arch >> *dni;
    if (arch.eof())return nullptr;
    arch >> c >> *cant >> c;
    plato = leeCadena(arch, ',');
    codRep = leeCadena(arch, '\n');

    dato[0] = codRep;
    dato[1] = guardaDemasDatos(dni, cant, plato);
    return dato;
}

bool compruebaregistro(void *clave, void *dato) {
    void **dat = (void **) clave;
    char *codRep = (char *) dat[0];
    char *codEvaluado = (char *) dato;
    return strcmp(codEvaluado, codRep) == 0;
}

void imprimeregistros(ofstream &arch, void *d, void *arr) {
    void **dato = (void **) d;
    void **arreglo = (void **) arr;
    char *cod, *nombre;
    int pos = 0;
    cod = (char *) dato[0];
    nombre = (char *) dato[1];
    arch << left << setw(15) << cod << nombre << right << endl;
    arch << "Ordenes:" << endl;
    while (arreglo[pos]) {
        void **pedido = (void **) arreglo[pos];
        int *dni = (int *) pedido[0], *cant = (int *) pedido[1];
        char *plato = (char *) pedido[2];
        arch << *dni << setw(10) << *cant << setw(10) << plato << endl;
        pos++;
    }
    arch << endl << endl;
}

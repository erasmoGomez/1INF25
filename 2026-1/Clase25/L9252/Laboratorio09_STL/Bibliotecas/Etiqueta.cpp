//
// Created by erasmo on 6/23/26.
//

#include "Etiqueta.hpp"
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

string Etiqueta::get_codigo() const {
    return codigo;
}

void Etiqueta::set_codigo(const string &codigo) {
    this->codigo = codigo;
}

string Etiqueta::get_nombre() const {
    return nombre;
}

void Etiqueta::set_nombre(const string &nombre) {
    this->nombre = nombre;
}

void Etiqueta::leer(ifstream &arch) {
    getline(arch, codigo, ',');
    if (arch.eof()) return;
    getline(arch, nombre);
}

void Etiqueta::imprimir(ofstream &arch) const {
    arch << left << setw(10) << codigo << nombre << endl;
}

void operator>>(ifstream &arch, class Etiqueta &eti) {
    eti.leer(arch);
}

void operator<<(ofstream &arch, const class Etiqueta &eti) {
    eti.imprimir(arch);
}
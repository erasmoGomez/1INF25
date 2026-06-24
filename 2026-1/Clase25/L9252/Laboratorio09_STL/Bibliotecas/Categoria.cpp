//
// Created by erasmo on 6/23/26.
//

#include "Categoria.hpp"

string Categoria::get_codigo() const {
    return codigo;
}

void Categoria::set_codigo(const string &codigo) {
    this->codigo = codigo;
}

string Categoria::get_nombre() const {
    return nombre;
}

void Categoria::set_nombre(const string &nombre) {
    this->nombre = nombre;
}

string Categoria::get_descripcion() const {
    return descripcion;
}

void Categoria::set_descripcion(const string &descripcion) {
    this->descripcion = descripcion;
}

bool Categoria::operator<(const Categoria &cat) const {
    return codigo < cat.codigo;
}

void Categoria::leer(ifstream &arch) {
    getline(arch, codigo, ',');
    if (arch.eof()) return;
    getline(arch, nombre, ',');
    getline(arch, descripcion);
}

void Categoria::imprimir(ofstream &arch) const {
    arch << left << setw(10) << codigo << setw(40) << nombre
         << descripcion << endl;
}

void operator>>(ifstream &arch, class Categoria &cat) {
    cat.leer(arch);
}

void operator<<(ofstream &arch, const class Categoria &cat) {
    cat.imprimir(arch);
}
#include <iostream>
#include <cstring>
#include "Categoria.h"
#include "Comunes.h"

using namespace std;

Categoria::Categoria() {
    nombre = nullptr;
    descripcion = nullptr;
}

Categoria::~Categoria() {
    delete[] nombre;
    delete[] descripcion;
}

Categoria::Categoria(const Categoria &other) {
    *this = other;
}

Categoria &Categoria::operator=(const Categoria &other) {
    set_codigo(other.codigo);
    set_nombre(other.nombre);
    set_descripcion(other.descripcion);
    return *this;
}

void Categoria::get_codigo(char *buffer) const {
    strcpy(buffer, codigo);
}

void Categoria::set_codigo(const char *cstr) {
    strcpy(codigo, cstr);
}

char *Categoria::get_nombre() const {
    return mi_strdup(nombre);
}

void Categoria::set_nombre(const char *cstr) {
    nombre = mi_strdup((char *) cstr);
}

char *Categoria::get_descripcion() const {
    return mi_strdup(descripcion);
}

void Categoria::set_descripcion(const char *cstr) {
    descripcion = mi_strdup((char *) cstr);
}

ostream &operator<<(ostream &out, Categoria &categoria) {
    out << categoria.codigo;
    out << ": ";
    out << categoria.nombre;
    out << " - ";
    out << categoria.descripcion;
    return out;
}

bool operator>>(istream &in, Categoria &categoria) {
    char buffer[120];
    in.getline(buffer, 120, ',');
    if (in.eof()) {
        return false;
    }
    categoria.set_codigo(buffer);
    in.getline(buffer, 120, ',');
    categoria.set_nombre(buffer);
    in.getline(buffer, 120, '\n');
    categoria.set_descripcion(buffer);
    return true;
}

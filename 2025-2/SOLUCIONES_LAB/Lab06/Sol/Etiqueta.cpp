#include <iostream>
#include <cstring>
#include "Etiqueta.h"
#include "Comunes.h"

using namespace std;

bool operator>>(istream &archivo_de_etiquetas, Etiqueta &etiqueta) {
    char codigo_buffer[7];
    char nombre_buffer[20];

    archivo_de_etiquetas.getline(codigo_buffer, 7, ',');
    if (archivo_de_etiquetas.eof())
        return false;
    archivo_de_etiquetas.getline(nombre_buffer, 20, '\n');

    Etiqueta etiqueta_local(codigo_buffer, nombre_buffer);
    etiqueta = etiqueta_local;
    return true;
}

ostream &operator<<(ostream &out, Etiqueta &etiqueta) {
    out << etiqueta.codigo;
    out << ": ";
    out << etiqueta.nombre;
    return out;
}

Etiqueta::Etiqueta() {
    nombre = nullptr;
}

Etiqueta::Etiqueta(const char *codigo, const char *nombre) {
    set_codigo(codigo);
    set_nombre(nombre);
}

Etiqueta::~Etiqueta() {
    delete[] nombre;
}

Etiqueta::Etiqueta(const Etiqueta &etiqueta) {
    *this = etiqueta;
}

Etiqueta &Etiqueta::operator=(const Etiqueta &other) {
    set_codigo(other.codigo);
    set_nombre(other.nombre);
    return *this;
}

void Etiqueta::get_codigo(char *buffer) {
    strcpy(buffer, codigo);
}

void Etiqueta::set_codigo(const char *cstr) {
    strcpy(codigo, cstr);
}

char *Etiqueta::get_nombre() const {
    return mi_strdup(nombre);
}

void Etiqueta::set_nombre(const char *cstr) {
    nombre = mi_strdup((char *) cstr);
}

#include <iostream>
#include "Canal.h"
#include "Comunes.h"

using namespace std;

Canal::Canal() {
    nombre = nullptr;
    categoria = nullptr;
    etiquetas = nullptr;
    cantidad_etiquetas = 0;
    for (int i = 0; i < MAX_VECTOR_ETIQUETAS; i++) {
        vector_etiquetas[i] = nullptr;
    }
    seguidores = CANAL_NO_LEIDO;
}

Canal::~Canal() {
    delete[] nombre;
    delete[] categoria;
    delete[] etiquetas;
    for (int i = 0; i < cantidad_etiquetas; i++) {
        delete[] vector_etiquetas[i];
    }
    cantidad_etiquetas = 0;
    seguidores = CANAL_NO_LEIDO;
}

Canal::Canal(const Canal &other) {
    *this = other;
}

Canal &Canal::operator=(const Canal &other) {
    nombre = other.get_nombre();
    categoria = other.get_categoria();
    etiquetas = other.get_etiquetas();
    cantidad_etiquetas = other.cantidad_etiquetas;
    for (int i = 0; i < cantidad_etiquetas; i++) {
        vector_etiquetas[i] = mi_strdup(other.vector_etiquetas[i]);
    }
    seguidores = other.seguidores;
    return *this;
}

char *Canal::get_nombre() const {
    return mi_strdup(nombre);
}

void Canal::set_nombre(const char *cstr) {
    nombre = mi_strdup((char *) cstr);
}

char *Canal::get_categoria() const {
    return mi_strdup(categoria);
}

void Canal::set_categoria(const char *cstr) {
    categoria = mi_strdup((char *) cstr);
}

char *Canal::get_etiquetas() const {
    return mi_strdup(etiquetas);
}

void Canal::set_etiquetas(const char *cstr) {
    etiquetas = mi_strdup((char *) cstr);
}

int Canal::get_seguidores() const {
    return seguidores;
}

void Canal::set_seguidores(int x) {
    seguidores = x;
}

void Canal::agregar_etiqueta(char *etiqueta) {
    // no es mi_strdup por que buscar_nombre_categoria retorna una copia de la etiqueta
    vector_etiquetas[cantidad_etiquetas] = etiqueta;
    cantidad_etiquetas += 1;
}

ostream &operator<<(ostream &out, Canal &canal) {
    out << canal.nombre;
    out << ": ";
    out << canal.seguidores;
    out << " - ";
    out << canal.categoria;
    out << "[";
    for (int i = 0; i < canal.cantidad_etiquetas; i++) {
        out << canal.vector_etiquetas[i];
        if (i >= 0 and i != canal.cantidad_etiquetas - 1)
            out << ", ";
    }
    out << "]";
    return out;
}

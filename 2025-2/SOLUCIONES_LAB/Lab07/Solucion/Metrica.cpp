//
// Created by Daniel Sanchez on 7/11/25.
//

#include "Metrica.h"

#include "Utils.h"

#include <cstring>
#include <fstream>
#include <iostream>

#include "GestorStreamers.h"

Metrica::Metrica() {
    id = 0;
    descripcion = nullptr;
    fecha_calculo = 0;
    fecha_expiracion = 0;
    estado = false;
}

Metrica::~Metrica() {
    delete[] descripcion;
}

Metrica &Metrica::operator=(const Metrica &m) {
    if (&m == this) {
        return *this;
    }
    set_id(m.id);
    set_descripcion(m.descripcion);
    set_fecha_calculo(m.fecha_calculo);
    set_fecha_expiracion(m.fecha_expiracion);
    set_estado(m.estado);
    return *this;
}

int Metrica::get_id() const {
    return id;
}

void Metrica::set_id(int n) {
    id = n;
}

void Metrica::get_descripcion(char *buffer) const {
    if (descripcion == nullptr) {
        buffer[0] = '\0';
    } else {
        strcpy(buffer, descripcion);
    }
}

void Metrica::set_descripcion(const char *buffer) {
    descripcion = my_strdup(buffer);
}

int Metrica::get_fecha_calculo() const {
    return fecha_calculo;
}

void Metrica::set_fecha_calculo(int n) {
    fecha_calculo = n;
}

int Metrica::get_fecha_expiracion() const {
    return fecha_expiracion;
}

void Metrica::set_fecha_expiracion(int n) {
    fecha_expiracion = n;
}

bool Metrica::get_estado() const {
    return estado;
}

void Metrica::set_estado(bool e) {
    estado = e;
}

void Metrica::leer(std::ifstream &arch) {
    char buffer[100], c;

    arch >> id >> c;

    arch.getline(buffer, 100, ',');
    set_descripcion(buffer);

    fecha_calculo = leer_fecha(arch);
    arch >> c;
    fecha_expiracion = leer_fecha(arch);
    arch >> c;

    set_estado(FECHA_REPORTE <= fecha_expiracion);
}

std::ostream & Metrica::imprimir(std::ostream &arch) const {
    arch << "MB-" << std::setw(4) << std::setfill('0') << id << std::setfill(' ') << "   ";
    imprimir_fecha(arch, fecha_calculo) << "   ";
    imprimir_fecha(arch, fecha_expiracion) << "  ";
    arch << (estado ? "ACTIVO  " : "EXPIRADA") << "  ";
    return arch;
}

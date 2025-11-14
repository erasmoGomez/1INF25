//
// Created by Daniel Sanchez on 7/11/25.
//

#include "Streamer.h"

#include "Utils.h"

#include <fstream>
#include <iomanip>

Streamer::Streamer() {
    id = 0;
    cuenta = nullptr;
    n_seguidores = 0;
    categoria = nullptr;
}

Streamer::~Streamer() {
    delete[] cuenta;
    delete[] categoria;
}

Streamer &Streamer::operator=(const Streamer &other) {
    if (&other == this) {
        return *this;
    }
    set_id(other.id);
    set_cuenta(other.cuenta);
    set_n_seguidores(other.n_seguidores);
    set_categoria(other.categoria);
    return *this;
}

int Streamer::get_id() const {
    return id;
}

void Streamer::set_id(int x) {
    id = x;
}

void Streamer::get_cuenta(char *buffer) const {
    if (cuenta == nullptr) {
        buffer[0] = '\0';
    } else {
        strcpy(buffer, cuenta);
    }
}

void Streamer::set_cuenta(const char *buffer) {
    cuenta = my_strdup(buffer);
}

int Streamer::get_n_seguidores() const {
    return n_seguidores;
}

void Streamer::set_n_seguidores(int n) {
    n_seguidores = n;
}

void Streamer::get_categoria(char *buffer) const {
    if (categoria == nullptr) {
        buffer[0] = '\0';
    } else {
        strcpy(buffer, categoria);
    }
}

void Streamer::set_categoria(const char *buffer) {
    categoria = my_strdup(buffer);
}

void Streamer::leer(std::ifstream &arch) {
    char buffer[48], c;
    int n;

    arch >> n >> c;
    set_id(n);

    arch.getline(buffer, 48, ',');
    set_cuenta(buffer);

    arch.getline(buffer, 48, ',');
    set_categoria(buffer);

    arch >> n >> c;
    set_n_seguidores(n);
}

std::ostream &Streamer::imprimir(std::ostream &arch) const {
    arch << std::right;
    arch << "[ST] CUENTA: " << std::setw(12) << cuenta << " | ";
    arch << "SEGUIDORES: " << std::setw(8) << n_seguidores << " | ";
    arch << "CATEGORIA: " << std::setw(12) << categoria << " | ";
    return arch;
}

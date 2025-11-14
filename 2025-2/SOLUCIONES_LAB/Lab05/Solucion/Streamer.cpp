//
// Created by Daniel Sanchez on 19/10/25.
//

#include "Streamer.h"

#include <cstring>
#include <fstream>
#include <iomanip>

Streamer::Streamer() {
    cuenta = nullptr;
    tiempo_total = 0;
    promedio_espectadores = 0.0;
    n_seguidores = 0;
    categoria = nullptr;
}

Streamer::~Streamer() {
    delete[] cuenta;
    delete[] categoria;
}

void Streamer::get_cuenta(char *cstr) const {
    if (cuenta == nullptr) {
        cstr[0] = '\0';
    } else {
        strcpy(cstr, cuenta);
    }
}

void Streamer::set_cuenta(const char *cstr) {
    delete[] cuenta;
    cuenta = new char[strlen(cstr) + 1];
    strcpy(cuenta, cstr);
}

long long Streamer::get_tiempo_total() const {
    return tiempo_total;
}

void Streamer::set_tiempo_total(long long x) {
    this->tiempo_total = x;
}

float Streamer::get_promedio_espectadores() const {
    return promedio_espectadores;
}

void Streamer::set_promedio_espectadores(float x) {
    this->promedio_espectadores = x;
}

int Streamer::get_n_seguidores() const {
    return n_seguidores;
}

void Streamer::set_n_seguidores(int x) {
    this->n_seguidores = x;
}

void Streamer::get_categoria(char *cstr) const {
    if (categoria == nullptr) {
        cstr[0] = '\0';
    } else {
        strcpy(cstr, categoria);
    }
}

void Streamer::set_categoria(const char *cstr) {
    delete[] categoria;
    categoria = new char[strlen(cstr) + 1];
    strcpy(categoria, cstr);
}

void Streamer::copiar(const Streamer &s) {
    set_cuenta(s.cuenta);
    set_tiempo_total(s.get_tiempo_total());
    set_promedio_espectadores(s.get_promedio_espectadores());
    set_n_seguidores(s.get_n_seguidores());
    set_categoria(s.categoria);
}

bool Streamer::leer_streamer(std::ifstream &f) {
    char buffer[32], c;
    f.getline(buffer, 32, ',');
    if (f.eof()) {
        return false;
    }
    set_cuenta(buffer);

    f >> tiempo_total >> c >> promedio_espectadores >> c >> n_seguidores >> c;

    f.getline(buffer, 32, '\n');
    set_categoria(buffer);

    return true;
}

void Streamer::mostrar_streamer(std::ostream &os) {
    os.precision(2);
    os << std::setw(16) << std::left << cuenta;
    os << std::setw(16) << std::left << categoria;
    os << std::setw(12) << std::right << n_seguidores;
    os << std::setw(12) << std::fixed << std::right << promedio_espectadores;
    os << std::setw(16) << std::right << tiempo_total << std::endl;
}

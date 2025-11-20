//
// Created by Erasmo on 19/11/25.
//

#include "Jugador.hpp"

void Jugador::leer(ifstream &input) {
    char buffer[20];
    input.getline(buffer, 20, ',');
    nombre = buffer;
    estado = true;
}

void Jugador::imprimir(ofstream &output) {
    output<<setw(10)<<nombre;
}

const string &Jugador::getNombre() const {
    return nombre;
}

void Jugador::setNombre(const string &nombre) {
    Jugador::nombre = nombre;
}

bool Jugador::isEstado() const {
    return estado;
}

void Jugador::setEstado(bool estado) {
    Jugador::estado = estado;
}

Jugador::Jugador() {

}

Jugador::~Jugador() {

}

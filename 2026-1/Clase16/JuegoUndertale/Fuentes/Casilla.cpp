//
// Created by erasmo on 5/13/26.
//

#include "Casilla.hpp"

bool Casilla::is_transitable() const {
    return transitable;
}

void Casilla::set_transitable(bool transitable) {
    this->transitable = transitable;
}

char Casilla::get_sprite() const {
    return sprite;
}

void Casilla::set_sprite(char sprite) {
    this->sprite = sprite;
}

Casilla::Casilla() {
}

Casilla::Casilla(bool transitable, char sprite) {
    this->transitable = transitable;
    this->sprite = sprite;
}

Casilla::~Casilla() {
}

void Casilla::imprimir(ostream& output) const{
    output << setw(1)<<'|' <<sprite<<setw(1)<<'|';
}

void operator<<(ostream & output, const class Casilla &c) {
    c.imprimir(output);
}
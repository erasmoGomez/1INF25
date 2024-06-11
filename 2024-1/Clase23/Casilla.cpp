//
// Created by Erasmo on 8/05/24.
//
#include "Casilla.hpp"
using namespace std;

Casilla::Casilla() {
    elemento = '_';
}

Casilla::Casilla(int x, int y, char e) {
    this->x = x;
    this->y = y;
    this->elemento = e;
}

int Casilla::getX() const {
    return x;
}

void Casilla::setX(int x) {
    Casilla::x = x;
}

int Casilla::getY() const {
    return y;
}

void Casilla::setY(int y) {
    Casilla::y = y;
}

char Casilla::getElemento() const {
    return elemento;
}

void Casilla::setElemento(char elemento) {
    Casilla::elemento = elemento;
}

void Casilla::leer(ifstream & input) {
    char extra;
    input>>x>>extra;
    input>>y>>extra;
    input>>elemento;
}

void Casilla::mostrar(ostream & output) {
    output << setw(1) << '|' << this->getElemento() << setw(1) << '|';
}

void operator << (ostream& output, class Casilla casilla ){
    casilla.mostrar(output);
}

void operator >> (ifstream& input, class Casilla &casilla ){
    casilla.leer(input);
}
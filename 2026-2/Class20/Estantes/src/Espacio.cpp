//
// Created by Erasmo on 22/10/25.
//

#include "Espacio.hpp"

Espacio::Espacio() {
    posX = 0;
    posY = 0;
    contenido = ' ';
}

Espacio::Espacio(const Espacio& orig) {
}

Espacio::~Espacio() {
}

void Espacio::SetPosY(int posY) {
    this->posY = posY;
}

int Espacio::GetPosY() const {
    return posY;
}

void Espacio::SetPosX(int posX) {
    this->posX = posX;
}

int Espacio::GetPosX() const {
    return posX;
}

void Espacio::SetContenido(char contenido) {
    this->contenido = contenido;
}

char Espacio::GetContenido() const {
    return contenido;
}

void Espacio::mostrar(ofstream& output) const {
    output << "[ " << contenido << " ]";
}

void operator<<(ofstream &output, const Espacio& e){
    e.mostrar(output);
}

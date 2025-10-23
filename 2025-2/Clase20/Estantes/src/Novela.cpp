//
// Created by Erasmo on 22/10/25.
//

#include "Novela.hpp"

Novela::Novela() {
    tipo = nullptr;
    peso = 0;
}

double Novela::getPeso() const {
    return peso;
}

void Novela::setPeso(double peso) {
    Novela::peso = peso;
}

void Novela::SetTipo(const char* tipo) {
    if(this->tipo != nullptr) delete this->tipo;
    this->tipo = new char[strlen(tipo)+1];
    strcpy(this->tipo, tipo);
}

void Novela::GetTipo(char* tipo) const {
    if(this->tipo == nullptr) tipo[0]=0;
    else strcpy(tipo, this->tipo);
}

Novela::Novela(const Novela &orig) {
    *this = orig;
}

void Novela::operator = (const Novela &orig) {
    char buffer[20];
    orig.GetTipo(buffer);
    SetTipo(buffer);
    setPeso(orig.getPeso());
}

Novela::~Novela() {
    delete tipo;
}

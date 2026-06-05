//
// Created by Erasmo on 22/10/25.
//

#include "Novela.hpp"

Novela::Novela() {
    tipo = nullptr;
    rating = 0;
}

double Novela::getRating() const {
    return rating;
}

void Novela::setRating(double rating) {
    Novela::rating = rating;
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
    Libro::operator=(orig); //Llamada al padre.
    char buffer[20];
    orig.GetTipo(buffer);
    SetTipo(buffer);
    setRating(orig.getRating());
}

void Novela::leer(ifstream & input) {
    //N, ABC321, El libro de la Costa, 2, 4, Historia, 1.0
    Libro::leer(input);
    char buffer[20];
    input.getline(buffer, 20, ',');
    SetTipo(buffer);
    input>>rating;
}

Novela::~Novela() {
    delete tipo;
}

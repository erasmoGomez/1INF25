//
// Created by Erasmo on 22/10/25.
//

#include "Novela.hpp"

Novela::Novela() {
    //AUTOMATICAMENTE LLAMA AL DEL PADRE
    rating = 0;
}

string Novela::get_tipo() const {
    return tipo;
}

void Novela::set_tipo(const string &tipo) {
    this->tipo = tipo;
}

double Novela::getRating() const {
    return rating;
}

void Novela::setRating(double rating) {
    Novela::rating = rating;
}


Novela::Novela(const Novela &orig) {
    *this = orig;
}

void Novela::operator = (const Novela &orig) {
    Libro::operator=(orig); //Llamada al padre.
    tipo = orig.tipo;
    setRating(orig.getRating());
}

void Novela::leer(ifstream & input) {
    //ABC321, El libro de la Costa, 2, 4, Historia, 1.0
    // LLAMADA EXPLICITA AL METODO DEL PADRE
    Libro::leer(input); // LLAMO AL METODO DE LECTURA DEL PADRE
    //Historia, 1.0
    char buffer[20];
    input.getline(buffer, 20, ',');
    tipo = buffer;
    input>>rating;
    input.get();
}

Novela::~Novela() {
}

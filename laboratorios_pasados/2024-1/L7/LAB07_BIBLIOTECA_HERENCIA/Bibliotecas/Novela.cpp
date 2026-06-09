//
// Created by USUARIO on 3/06/2026.
//

#include "Novela.hpp"


Novela::Novela(){
    inicializar();
}

Novela::Novela(const class Novela& novela){
    inicializar();
    *this = novela;
}

char* Novela::get_tipo() const{
    char *copia = Utils::asignar_cadena(this->tipo);
    return copia;
}

void Novela::set_tipo(const char* tipo){
    delete [] this->tipo;
    this->tipo = Utils::asignar_cadena(tipo);
}

double Novela::get_rating() const{
    return rating;
}

void Novela::set_rating(double rating){
    this->rating = rating;
}


void Novela::inicializar(){
    tipo = nullptr;
    rating = 0;
}

Novela& Novela::operator=(const class Novela& novela){
    if (this != &novela){
        Libro::operator=(novela);

        delete [] this->tipo;
        this->tipo = novela.get_tipo();
        rating = novela.get_rating();
    }
    return *this;
}

void Novela::leer(ifstream& in){
    Libro::leer(in);
    this->tipo = Utils::leer_cadena(in, ',');
    this->rating = Utils::leer_double(in);
}

Novela::~Novela(){
    delete [] tipo;
}

void Novela::imprimir_data_novela(ofstream& out) const{
    char *codigo = get_codigo();
    out << left << setw(12) << codigo;
    delete [] codigo;
    char *nombre = get_nombre();
    out << left << setw(30) << nombre;
    delete [] nombre;
    out << right << setw(6) << get_ancho();
    out << right << setw(8) << get_alto();
    out << right << setw(10) << get_rating();
    out << endl;
}

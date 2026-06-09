//
// Created by USUARIO on 3/06/2026.
//

#include "Enciclopedia.hpp"

Enciclopedia::Enciclopedia(){
    inicializar();
}

Enciclopedia::Enciclopedia(const class Enciclopedia& enc){
    inicializar();
    *this = enc;
}

int Enciclopedia::get_volumen() const{
    return volumen;
}

void Enciclopedia::set_volumen(int volumen){
    this->volumen = volumen;
}

double Enciclopedia::get_peso() const{
    return peso;
}

void Enciclopedia::set_peso(double peso){
    this->peso = peso;
}

void Enciclopedia::inicializar(){
    volumen = 0;
    peso = 0;
}

Enciclopedia& Enciclopedia::operator=(const Enciclopedia& enc){
    if (this != &enc){
        //PARA LOS ATRIBUTOS DEL PADRE
        Libro::operator=(enc);
        volumen = enc.get_volumen();
        peso = enc.get_peso();
    }
    return *this;
}

void Enciclopedia::leer(ifstream& in){
    Libro::leer(in);
    set_volumen(Utils::leer_int(in));
    set_peso(Utils::leer_double(in));
}

void Enciclopedia::imprimir_data_enciclopedia(ofstream& out) const{
    char *codigo = get_codigo();
    out << left << setw(12) << codigo;
    delete [] codigo;
    char *nombre = get_nombre();
    out << left << setw(30) << nombre;
    delete [] nombre;
    out << right << setw(6) << get_ancho();
    out << right << setw(8) << get_alto();
    out << right << setw(10) << get_peso();
    out << endl;
}



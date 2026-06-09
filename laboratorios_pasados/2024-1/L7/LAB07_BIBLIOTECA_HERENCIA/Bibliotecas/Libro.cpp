//
// Created by USUARIO on 3/06/2026.
//

#include "Libro.hpp"

Libro::Libro(){
    inicializar();
}

Libro::Libro(const class Libro& libro){
    inicializar();
    *this = libro;
}

char* Libro::get_codigo() const{
    char *copia = Utils::asignar_cadena(this->codigo);
    return copia;
}

void Libro::set_codigo(const char* codigo){
    delete [] this->codigo;
    this->codigo = Utils::asignar_cadena(codigo);
}

char* Libro::get_nombre() const{
    char *copia = Utils::asignar_cadena(this->nombre);
    return copia;
}

void Libro::set_nombre(const char* nombre){
    delete [] this->nombre;
    this->nombre = Utils::asignar_cadena(nombre);
}

int Libro::get_ancho() const{
    return ancho;
}

void Libro::set_ancho(int ancho){
    this->ancho = ancho;
}

int Libro::get_alto() const{
    return alto;
}

void Libro::set_alto(int alto){
    this->alto = alto;
}

double Libro::get_peso() const{
    return peso;
}

void Libro::set_peso(double peso){
    this->peso = peso;
}

bool Libro::is_colocado() const{
    return colocado;
}

void Libro::set_colocado(bool colocado){
    this->colocado = colocado;
}

void Libro::inicializar(){
    codigo = nullptr;
    nombre = nullptr;
    alto = 0;
    ancho = 0;
    peso = 0;
    colocado = false;
}

Libro& Libro::operator=(const class Libro& libro){
    if (this !=&libro){
        /*
        ERROR PORQUE HAY MEMORY LEAK:
        - get_codigo hace copia y devuelve char*
        - set_codigo hace copia del char* y devuelve otro char*
        set_codigo(libro.get_codigo());
        set_nombre(libro.get_nombre());
        set_alto(libro.get_alto());
        set_ancho(libro.get_ancho());
        set_peso(libro.get_peso());
        set_colocado(libro.is_colocado());
        */
        delete [] this->codigo;
        this->codigo = libro.get_codigo();
        delete [] this->nombre;
        this->nombre = libro.get_nombre();

        set_alto(libro.get_alto());
        set_ancho(libro.get_ancho());
        set_peso(libro.get_peso());
        set_colocado(libro.is_colocado());

    }
    return *this;
}

void Libro::leer(ifstream& in){
    this->codigo = Utils::leer_cadena(in, ',');
    this->nombre = Utils::leer_cadena(in, ',');
    this->ancho = Utils::leer_int(in);
    this->alto = Utils::leer_int(in);
}

Libro::~Libro(){
    delete [] this->codigo;
    delete [] this->nombre;
}

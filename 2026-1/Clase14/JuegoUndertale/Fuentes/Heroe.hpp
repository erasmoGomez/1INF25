//
// Created by erasmo on 5/6/26.
//

#ifndef JUEGOUNDERTALE_HEROE_HPP
#define JUEGOUNDERTALE_HEROE_HPP

#include "Utils.hpp"

class Heroe {
private:
    char* nombre;
    int vida;
    int vida_maxima;
    int ataque;
    int defensa;
    int fila;
    int columna;
public:
    Heroe(); // Constructor por defecto - Constructor sin parametros;
    void imprimir();
};


#endif //JUEGOUNDERTALE_HEROE_HPP
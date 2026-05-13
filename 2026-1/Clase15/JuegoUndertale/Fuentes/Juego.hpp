//
// Created by erasmo on 5/12/26.
//

#ifndef JUEGOUNDERTALE_JUEGO_HPP
#define JUEGOUNDERTALE_JUEGO_HPP
#include "Personaje.hpp"
class Juego {
private:
    Personaje personajes[20]{};
    int cantidad_personajes;
public:
    Juego(); //Constructor
    void cargar_personajes(const char*);
    void imprimir_personajes(const char*);
    //void operator +=(Personaje p);
    void jugar();
};
#endif //JUEGOUNDERTALE_JUEGO_HPP
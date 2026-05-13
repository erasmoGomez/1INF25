//
// Created by erasmo on 5/12/26.
//

#ifndef JUEGOUNDERTALE_JUEGO_HPP
#define JUEGOUNDERTALE_JUEGO_HPP
#include "Mapa.hpp"
#include "Personaje.hpp"
class Juego {
private:
    Personaje personajes[20]{};
    int cantidad_personajes;
    Mapa mapas[10]{};
    int cantidad_mapas;
public:
    Juego(); //Constructor
    void cargar_personajes(const char*);
    void imprimir_personajes(const char*);
    void cargar_mapas(const char*);
    void imprimir_mapa(int);
    void jugar();

    void colocar_heroes();
};
#endif //JUEGOUNDERTALE_JUEGO_HPP
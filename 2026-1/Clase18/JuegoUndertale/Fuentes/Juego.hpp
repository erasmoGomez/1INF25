//
// Created by erasmo on 5/12/26.
//

#ifndef JUEGOUNDERTALE_JUEGO_HPP
#define JUEGOUNDERTALE_JUEGO_HPP
#include "Utils.hpp"
#include "Mapa.hpp"
#include "Guerrero.hpp"
#include "Mago.hpp"
#include "Personaje.hpp"
class Juego {
private:
    Personaje personajes[20]{};
    Personaje* personajes_ptr;
    int cantidad_personajes;
    Mapa mapas[10]{};
    int cantidad_mapas;
    int mapa_actual;
public:
    Juego(); //Constructor
    void cargar_personajes(const char*);
    void imprimir_personajes(const char*);
    void cargar_mapas(const char*);
    void imprimir_mapa(int);
    void jugar();
    int conseguir_indice(char p);
    void colocar_personajes();
    void pintar();
    void cargar_items(const char*);

};
#endif //JUEGOUNDERTALE_JUEGO_HPP
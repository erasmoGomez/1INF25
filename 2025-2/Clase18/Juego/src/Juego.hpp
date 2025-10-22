//
// Created by Erasmo on 26/09/25.
//

#ifndef JUEGO_JUEGO_HPP
#define JUEGO_JUEGO_HPP

#include "Heroe.hpp"
#include "Mapa.hpp"

class Juego {
private: //Atributos en la parte privada
    class Heroe heroes[10];
    int cantidad_heroes;
    class Mapa mapa;
public: //Metodos en la parte publica
    Juego();
    void cargar_heroes();
    void mostrar_heroes();
    void cargar_mapa();
    void mostrar_mapa();
    void colocar_heroes();
    void pintar();
    void jugar();
    int conseguir_indice(char h);
    void cargar_items();
};


#endif //JUEGO_JUEGO_HPP

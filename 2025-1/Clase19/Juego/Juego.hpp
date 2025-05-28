/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Juego.hpp
 * Author: hecto
 *
 * Created on May 7, 2025, 4:20 PM
 */

#ifndef JUEGO_HPP
#define JUEGO_HPP
#include "Heroe.hpp"
#include "Mapa.hpp"
class Juego {
public:
    Juego(); //Constructor Defecto
    Juego(int); //Constructor con Parametros
    Juego(const Juego& orig); //Constructor copia
    virtual ~Juego(); //Deestructor
    void cargar_heroes();
    void cargar_items();
    void mostrar_heroes();
    void cargar_mapa();
    void mostrar_mapa();
    void colocar_heroes();
    void jugar();
    int conseguir_indice(char);
    void pintar();
    void mostrar_items();
private:
    class Heroe heroes[10]{};
    int cantidad_heroes;
    Mapa mapa;
};

#endif /* JUEGO_HPP */


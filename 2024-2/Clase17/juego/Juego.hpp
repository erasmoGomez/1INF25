/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Juegoi.hpp
 * Author: ASUS
 *
 * Created on May 7, 2024, 9:48 AM
 */

#ifndef JUEGOI_HPP
#define JUEGOI_HPP

#include "Casilla.hpp"
#include "Heroe.hpp"
#include "mapa.hpp"

class Juego{
private:
    Mapa mapa;
    Heroe heroes[10];
    int n_heroes;
public:
    Juego();
    void cargar_juego();
    void jugar();
    void mostrar_mapa();
    void carga_mapa();
    void carga_heroes();
    void cargar_items();
    void colocar_heroes();
    int conseguir_indice(char);
    void pintar();
};

#endif /* JUEGOI_HPP */


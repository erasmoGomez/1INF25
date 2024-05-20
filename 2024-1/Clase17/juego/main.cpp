/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Erasmo G. Montoya
 *
 * Created on May 6, 2024, 6:36 PM
 */

#include "Juego.hpp"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Juego juego;
    juego.cargar_juego();
    //juego.mostrar_mapa();
    juego.colocar_heroes();
    juego.mostrar_mapa();
    return 0;
}


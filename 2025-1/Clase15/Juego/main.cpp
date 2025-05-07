/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Erasmo Gomez
 * Description: 
 * Created on May 6, 2025, 5:47 PM
 */
#include "Juego.hpp"

/*
 * 
 */
int main(int argc, char** argv) {
    class Juego juego;
    juego.cargar_heroes();
    juego.mostrar_heroes();
    
    juego.cargar_mapa();
    return 0;
}


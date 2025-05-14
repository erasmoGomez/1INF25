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
    juego.colocar_heroes();
    juego.mostrar_mapa();
    juego.jugar();
//    class Heroe h1;
//    h1.setNombre("Erasmo");
//    char buffer[20];
//    h1.getNombre(buffer);
//    buffer[0] = 'e';
//    h1.setNombre(buffer);
//    char buffer2[20];
//    h1.getNombre(buffer2);
//    cout<<buffer2<<endl;
    
//    Heroe h;
//    h.setPosX(10);
//    h.setPosX(h.getPosX()+1);
    return 0;
}


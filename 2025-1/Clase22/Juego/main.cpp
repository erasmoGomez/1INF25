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
#include "Mago.hpp"
#include "Item.hpp"
/*
 * 
 */
int main(int argc, char** argv) {
//    class Heroe heroe;
//    heroe.setNombre("Teemo");
//    heroe.setHp(50);
//    
//    class Heroe heroe2;
//    heroe2.setNombre("Lux"); //Mago
//    //Aplicando Herencia
//    class Mago mago1;
//    mago1.setNombre("Lux");
//    mago1.setDefensa(10);
//    mago1.setFuerza(10);
//    mago1.setHp(80);
//    mago1.setMana(75.3);
//    mago1.setId("ABC123");
//    mago1.setPosX(10);
//    mago1.setPosY(10);
//    mago1.mostrar_heroe(cout);
    Juego juego;
    juego.cargar_heroes();
    juego.cargar_items();
    juego.cargar_mapa();
    juego.colocar_heroes();
    juego.mostrar_items(0);
    //juego.jugar();
            
    return 0;
}


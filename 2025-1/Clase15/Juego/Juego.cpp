/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Juego.cpp
 * Author: hecto
 * 
 * Created on May 7, 2025, 4:20 PM
 */

#include "Juego.hpp"
#include "Mapa.hpp"

Juego::Juego() {
    cantidad_heroes = 0;
}

Juego::Juego(const Juego& orig) {
    *this = orig;
}

Juego::~Juego() {
}

void Juego::cargar_heroes(){
    ifstream input("heroes.csv", ios::in);
    while(true){
        class Heroe h;
        h.cargar_info(input);
        if(input.eof())break;
        heroes[cantidad_heroes] = h;
        cantidad_heroes++;
    }
}

void Juego::mostrar_heroes(){
    ofstream output("reporte_heroes.txt", ios::out);
    for(int i = 0; i< cantidad_heroes; i++)
        heroes[i].mostrar_info(output);
}

void Juego::cargar_mapa(){
    ifstream input("mapa_grande.csv", ios::in);
    mapa.cargar_mapa(input);
    mapa.mostrar_mapa();
}
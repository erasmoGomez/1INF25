/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Espacio.cpp
 * Author: Erasmo G. Montoya
 * 
 * Created on May 23, 2024, 10:20 PM
 */

#include "Espacio.hpp"

Espacio::Espacio() {
    contenido = ' ';
    posx = 0;
    posy = 0;
}

char Espacio::getContenido() const {
    return contenido;
}

void Espacio::setContenido(char contenido) {
    Espacio::contenido = contenido;
}

int Espacio::getPosx() const {
    return posx;
}

void Espacio::setPosx(int posx) {
    Espacio::posx = posx;
}

int Espacio::getPosy() const {
    return posy;
}

void Espacio::setPosy(int posy) {
    Espacio::posy = posy;
}

void Espacio::muestra(ofstream& output) {
    output << "[ " << contenido << " ]";
}

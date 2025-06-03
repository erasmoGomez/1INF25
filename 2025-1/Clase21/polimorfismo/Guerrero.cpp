/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Guerrero.cpp
 * Author: hecto
 * 
 * Created on May 30, 2025, 5:20 AM
 */

#include "Guerrero.hpp"

Guerrero::Guerrero(const char* nombre_in, int nivel_in, int fuerza_in){
    Personaje::setNombre(nombre_in);
    Personaje::setNivel(nivel_in);
    fuerza = fuerza_in;
}

Guerrero::Guerrero() {
}

Guerrero::Guerrero(const Guerrero& orig) {
}

Guerrero::~Guerrero() {
}


void Guerrero::mostrar() const {
    Personaje::mostrar();
    std::cout << "Fuerza: " << fuerza << std::endl;
}

void Guerrero::leer(ifstream&input){
    Personaje::leer(input);
    input>>fuerza;
    input.get();
}

void Guerrero::realizar_accion_pura(){
    
}
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Mago.cpp
 * Author: hecto
 * 
 * Created on May 30, 2025, 5:20 AM
 */

#include "Mago.hpp"

Mago::Mago() {
}

Mago::Mago(const Mago& orig) {
}

Mago::~Mago() {
}

Mago::Mago(const char* nombre_in, int nivel_in, int poder_magico_in, int mana_in) {
    Personaje::setNombre(nombre_in);
    Personaje::setNivel(nivel_in);
    poder_magico = poder_magico_in;
    mana = mana_in;
}

void Mago::mostrar() const {
    Personaje::mostrar();
    cout << "Poder Magico: " << poder_magico << endl;
    cout << "Mana: " << mana << endl;
}

void Mago::leer(ifstream&input){
    Personaje::leer(input);
    input>>poder_magico;
    input.get();
    input>>mana;
    input.get();
}
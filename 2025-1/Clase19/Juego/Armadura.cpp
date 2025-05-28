/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Armadura.cpp
 * Author: hecto
 * 
 * Created on May 14, 2025, 5:38 PM
 */

#include "Armadura.hpp"

Armadura::Armadura() {
}

Armadura::Armadura(const Armadura& orig) {
}

Armadura::~Armadura() {
}

void Armadura::leer(ifstream&input){
    //Llama a la clase Padre y su metodo de lectura
    Item::leer(input);
    //147
    //Proceso de lectura de la clase hija
    input>>modificador_defensa;
    input.get();
}

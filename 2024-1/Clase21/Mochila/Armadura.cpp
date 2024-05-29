/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Armadura.cpp
 * Author: Erasmo G. Montoya
 * 
 * Created on May 27, 2024, 5:41 PM
 */

#include "Armadura.hpp"

Armadura::Armadura() {
}

Armadura::Armadura(const Armadura& orig) {
}

Armadura::~Armadura() {
}

void Armadura::SetModificador_def(int modificador_def) {
    this->modificador_def = modificador_def;
}

int Armadura::GetModificador_def() const {
    return modificador_def;
}

void Armadura::leer(ifstream &input){
    //Lectura de la clase padre
    Item::leer(input);
    //Lectura de la clase derivada
    int valor;
    input>>valor;
    input.get();
    modificador_def = valor;
}

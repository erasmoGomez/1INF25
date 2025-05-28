/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Consumible.cpp
 * Author: hecto
 * 
 * Created on May 14, 2025, 5:40 PM
 */

#include "Consumible.hpp"

Consumible::Consumible() {
}

Consumible::Consumible(const Consumible& orig) {
}

Consumible::~Consumible() {
}

void Consumible::leer(ifstream&input){
    //Llama a la clase Padre y su metodo de lectura
    Item::leer(input);
    //147
    //Proceso de lectura de la clase hija
    input>>modificador_hp;
    input.get();
    
}

void Consumible::mostrar(ostream&output) const{
    output<<"Item de tipo Consumible"<<endl;
    Item::mostrar(output);
    output<<"Modificador Salud:"<<modificador_hp<<endl;
}
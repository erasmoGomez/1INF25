/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Consumible.cpp
 * Author: Erasmo G. Montoya
 * 
 * Created on May 27, 2024, 5:40 PM
 */

#include "Consumible.hpp"

Consumible::Consumible() {
}

Consumible::Consumible(const Consumible& orig) {
}

Consumible::~Consumible() {
}

void Consumible::SetModificador_hp(int modificador_hp) {
    this->modificador_hp = modificador_hp;
}

int Consumible::GetModificador_hp() const {
    return modificador_hp;
}

void Consumible::leer(ifstream &input){
    //Lectura de la clase padre
    Item::leer(input);
    //Lectura de la clase derivada
    int valor;
    input>>valor;
    input.get();
    modificador_hp = valor;
}

void Consumible::mostrar(ofstream&output){
    Item::mostrar(output);
    bool displayQ = GetEquipadoQ();
    if(!displayQ)
        output<<"El modificador de HP es: "<<modificador_hp<<endl;
    else
        output<<"El item se encuentra equipado"<<endl;
}
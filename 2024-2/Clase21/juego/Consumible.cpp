/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Consumible.cpp
 * Author: Erasmo G. Montoya
 * 
 * Created on October 22, 2024, 6:12 PM
 */

#include "Consumible.hpp"

Consumible::Consumible() {
    modificador_hp = 0;
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

void Consumible::leer(ifstream&input){
    //LLamar a la clase padre y su metodo de lectura
    //Sword,A sharp and sturdy sword.,
    //Item - Consumible/Armadura/Arma
    Item::leer(input); // nombre y descripcion llenos para consumible
    //Se usa el proceso de lectura de la clase hija
    //147
    //Consumible/Armadura/Arma
    input>>modificador_hp;
    input.get();
    Item::SetEquipadoQ(false);
}

void Consumible::mostrar(){
    Item::mostrar();
    if(not IsEquipadoQ())
        cout<<"El modificador de HP es "<<modificador_hp<<endl;
    else
        cout<<"El item se encuentra equipado"<<endl;
                
}
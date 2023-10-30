/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Consumable.cpp
 * Author: ASUS
 * 
 * Created on October 18, 2023, 7:58 AM
 */

#include "Consumable.hpp"

Consumable::Consumable() {
    hp=0;
}

Consumable::Consumable(const Consumable& orig) {
}

Consumable::~Consumable() {
}

void Consumable::actualiza(){
    //Incrementar el valor de hp
    int value = 0;
    value = GetValue();
    SetValue(value + hp);
    hp = value + hp;
}

void Consumable::muestra(ofstream &output){
    output<<left<<"incremento HP: "<<hp<<endl;
}
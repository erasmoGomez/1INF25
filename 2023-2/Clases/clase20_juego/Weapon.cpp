/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Weapon.cpp
 * Author: ASUS
 * 
 * Created on October 18, 2023, 7:57 AM
 */

#include "Weapon.hpp"

Weapon::Weapon() {
    att = 100;
}

Weapon::Weapon(const Weapon& orig) {
}

Weapon::~Weapon() {
}

void Weapon::actualiza(){
    //Incrementar el valor de la arma
    int value = 0;
    value = GetValue();
    SetValue(value + att);
    att = value + att;
}

void Weapon::muestra(ofstream &output){
    output<<left<<"incremento ATT: "<<att<<endl;
}

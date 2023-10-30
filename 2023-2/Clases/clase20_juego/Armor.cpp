/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Armor.cpp
 * Author: ASUS
 * 
 * Created on October 18, 2023, 7:54 AM
 */

#include "Armor.hpp"

Armor::Armor() {
    def=100;
}

Armor::Armor(const Armor& orig) {
}

Armor::~Armor() {
}

void Armor::actualiza(){
    //Concatenamos la defensa a la descripcion
    char description[200];
    char buffer_desc[300];
    GetDescription(description);
    
    stringstream ss;
    ss << description << " Se Incrementa: "<<GetValue()+def<< " a la defensa.";
    strcpy(buffer_desc,ss.str().c_str());
    SetDescription(buffer_desc);
    
}

void Armor::muestra(ofstream &output){
    char buffer_desc[300];
    GetDescription(buffer_desc);
    output<<left<<"incremento Def: "<<buffer_desc<<endl;
}
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

void Consumible::setModificador_hp(int modificador_hp) {
    this->modificador_hp = modificador_hp;
}

int Consumible::getModificador_hp() const {
    return modificador_hp;
}

void Consumible::leer(ifstream&input){
    //Llama a la clase Padre y su metodo de lectura
    //cout<<"Me llamaron de cargar_items y soy Consumible"<<endl;
    Item::leer(input);
    //147
    //Proceso de lectura de la clase hija
    input>>modificador_hp;
    input.get();
    
}

void Consumible::mostrar(ostream&output) const{
    Item::mostrar(output);
    output<<setw(5)<<left<<modificador_hp<<setw(10)<<(IsEquipado() ? "EQUIPADO" : "NO EQUIPADO")<<endl;
}

int Consumible::get_valor(){
    return modificador_hp;
}
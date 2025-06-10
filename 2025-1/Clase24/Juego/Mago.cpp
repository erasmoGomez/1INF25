/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Mago.cpp
 * Author: hecto
 * 
 * Created on May 14, 2025, 4:39 PM
 */

#include "Mago.hpp"

Mago::Mago() {
}

Mago::Mago(const Mago& orig) {
}

Mago::~Mago() {
}

void Mago::setMana(double mana) {
    this->mana = mana;
}

double Mago::getMana() const {
    return mana;
}

void Mago::mostrar_heroe(ostream& output) const{
    Heroe::mostrar_heroe(output);
    cout<< "Informacion del Mago"<<endl;
    dibujar_barra(mana, 100, "Mana   ", output);
    //dibujar_barra(getPosX(), 100, "PosX   ", output);
    output << "===============================" << endl;
    cout<<kills<<endl; //Protegida
    cout<<getKills()<<endl; //Con get protegida
}
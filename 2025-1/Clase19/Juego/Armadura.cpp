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

void Armadura::setModificador_defensa(int modificador_defensa) {
    this->modificador_defensa = modificador_defensa;
}

int Armadura::getModificador_defensa() const {
    return modificador_defensa;
}

void Armadura::leer(ifstream&input){
    //Llama a la clase Padre y su metodo de lectura
    Item::leer(input);
    //147
    //Proceso de lectura de la clase hija
    input>>modificador_defensa;
    input.get();
}

void Armadura::mostrar(ostream&output) const{
    Item::mostrar(output);
    output<<setw(5)<<left<<modificador_defensa<<setw(10)<<(IsEquipado() ? "EQUIPADO" : "NO EQUIPADO")<<endl;
}
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Inventario.cpp
 * Author: hecto
 * 
 * Created on May 27, 2025, 5:36 PM
 */

#include "Inventario.hpp"

Inventario::Inventario() {
    n_armaduras = 0;
    n_armas = 0;
    n_consumibles = 0;
}

Inventario::Inventario(const Inventario& orig) {
}

Inventario::~Inventario() {
}

void Inventario::SetN_armas(int n_armas) {
    this->n_armas = n_armas;
}

int Inventario::GetN_armas() const {
    return n_armas;
}

void Inventario::SetN_armaduras(int n_armaduras) {
    this->n_armaduras = n_armaduras;
}

int Inventario::GetN_armaduras() const {
    return n_armaduras;
}

void Inventario::SetN_consumibles(int n_consumibles) {
    this->n_consumibles = n_consumibles;
}

int Inventario::GetN_consumibles() const {
    return n_consumibles;
}


void Inventario::cargar_items(ifstream &input, char*tipo){
    //Inventario -> Item -> Consumible/Armadura/Arma
    if(strcmp(tipo, "Consumable")==0){
        ventana_consumibles[n_consumibles].leer(input);
        n_consumibles++;
    }
    if(strcmp(tipo, "Weapon")==0){
        ventana_armas[n_armas].leer(input);
        n_armas++;
    }
    if(strcmp(tipo, "Armor")==0){
        ventana_armaduras[n_armaduras].leer(input);
        n_armaduras++;
    }
}

void Inventario::mostrar_items(ostream& output) const{
    output<< "Ventana Consumibles"<<endl;
    for(int i=0; i<n_consumibles; i++)
        ventana_consumibles[i].mostrar(output);
}
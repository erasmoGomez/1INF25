/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Mochila.cpp
 * Author: Erasmo G. Montoya
 * 
 * Created on October 22, 2024, 5:45 PM
 */

#include "Mochila.hpp"

Mochila::Mochila() {
}

Mochila::Mochila(const Mochila& orig) {
}

Mochila::~Mochila() {
}

void Mochila::SetN_armas(int n_armas) {
    this->n_armas = n_armas;
}

int Mochila::GetN_armas() const {
    return n_armas;
}

void Mochila::SetN_armaduras(int n_armaduras) {
    this->n_armaduras = n_armaduras;
}

int Mochila::GetN_armaduras() const {
    return n_armaduras;
}

void Mochila::SetN_consumibles(int n_consumibles) {
    this->n_consumibles = n_consumibles;
}

int Mochila::GetN_consumibles() const {
    return n_consumibles;
}

void Mochila::agregar_item(ifstream& input, char* tipo){
    //Mochila- Item - Consumible/Armadura/Arma
    if(strcmp(tipo, "Consumable")==0){
        bolsillo_consumibles[n_consumibles].leer(input);
        n_consumibles++;
    }
    if(strcmp(tipo, "Weapon")==0){
        bolsillo_armas[n_armas].leer(input);
        n_armas++;
    }
    if(strcmp(tipo, "Armor")==0){
        bolsillo_armaduras[n_armaduras].leer(input);
        n_armaduras++;
    }
}

void Mochila::mostrar(ofstream&){
    for(int i=0; i<n_consumibles;i++)
        bolsillo_consumibles[i].mostrar(output);
}

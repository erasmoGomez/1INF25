/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Mochila.cpp
 * Author: Erasmo G. Montoya
 * 
 * Created on May 27, 2024, 5:37 PM
 */

#include "Mochila.hpp"

Mochila::Mochila() {
    n_consumibles = 0;
    n_armas = 0;
    n_armaduras = 0;
}

Mochila::Mochila(const Mochila& orig) {
    
}

Mochila::~Mochila() {
}

void Mochila::SetN_armaduras(int n_armaduras) {
    this->n_armaduras = n_armaduras;
}

int Mochila::GetN_armaduras() const {
    return n_armaduras;
}

void Mochila::SetN_armas(int n_armas) {
    this->n_armas = n_armas;
}

int Mochila::GetN_armas() const {
    return n_armas;
}

void Mochila::SetN_consumibles(int n_consumibles) {
    this->n_consumibles = n_consumibles;
}

int Mochila::GetN_consumibles() const {
    return n_consumibles;
}

void Mochila::agregar_item(ifstream& input_items, char *tipo){
    if(strcmp(tipo, "Consumable")==0){
//        class Consumible c;
//        c.leer(input_items);
        bolsillo_consumibles[n_consumibles].leer(input_items);
        n_consumibles++;
    }
    if(strcmp(tipo, "Armor")==0){
        bolsillo_armaduras[n_armaduras].leer(input_items);
        n_armaduras++; 
    }
    if(strcmp(tipo, "Weapon")==0){
        bolsillo_armas[n_armas].leer(input_items);
        n_armas++;  
    }
}

int Mochila::buscar_consumible(const char* nombre){
    char nombre_item_consumible[20];
    for(int i=0; i<n_consumibles; i++){
        bolsillo_consumibles[i].GetNombre(nombre_item_consumible);
        if(strcmp(nombre_item_consumible, nombre)==0){
            if(!bolsillo_consumibles[i].GetEquipadoQ()){
                bolsillo_consumibles[i].SetEquipadoQ(true);
                return bolsillo_consumibles[i].GetModificador_hp();
            }
            else{
                return 0;
            }            
        }     
    }
    return -1;
}

int Mochila::buscar_armadura(const char* nombre){
    char nombre_item_armadura[20];
    for(int i=0; i<n_armaduras; i++){
        bolsillo_armaduras[i].GetNombre(nombre_item_armadura);
        if(strcmp(nombre_item_armadura, nombre)==0){
            if(!bolsillo_armaduras[i].GetEquipadoQ()){
                bolsillo_armaduras[i].SetEquipadoQ(true);
                return bolsillo_armaduras[i].GetModificador_def();
            }
            else{
                return 0;
            }            
        }
            
    }
    return -1;
}

int Mochila::buscar_arma(const char* nombre){
    char nombre_item_arma[20];
    for(int i=0; i<n_armas; i++){
        bolsillo_armas[i].GetNombre(nombre_item_arma);
        if(strcmp(nombre_item_arma, nombre)==0){
            if(!bolsillo_armas[i].GetEquipadoQ()){
                bolsillo_armas[i].SetEquipadoQ(true);
                return bolsillo_armas[i].GetModificador_att();
            }
            else{
                return 0;
            }            
        }
            
    }
    return -1;
}

void Mochila::mostrar(ofstream &output){
    for(int i=0; i<n_consumibles;i++)
        bolsillo_consumibles[i].mostrar(output);
    for(int i=0; i<n_armas;i++)
        bolsillo_armas[i].mostrar(output);
    for(int i=0; i<n_armaduras;i++)
        bolsillo_armaduras[i].mostrar(output);
}
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
    n_armaduras = 0;
    n_armas = 0;
    n_consumibles = 0;
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

void Mochila::agregar_item(ifstream& input, char* tipo) {
    //Mochila- Item - Consumible/Armadura/Arma
    if (strcmp(tipo, "Consumable") == 0) {
        bolsillo_consumibles[n_consumibles].leer(input);
        n_consumibles++;
    }
    if (strcmp(tipo, "Weapon") == 0) {
        bolsillo_armas[n_armas].leer(input);
        n_armas++;
    }
    if (strcmp(tipo, "Armor") == 0) {
        bolsillo_armaduras[n_armaduras].leer(input);
        n_armaduras++;
    }
}

void Mochila::mostrar() {
    cout << "Bolsillo Consumibles" << endl;
    for (int i = 0; i < n_consumibles; i++)
        bolsillo_consumibles[i].mostrar();
    cout << "Bolsillo Armaduras" << endl;
    for (int i = 0; i < n_armaduras; i++)
        bolsillo_armaduras[i].mostrar();
    cout << "Bolsillo Armas" << endl;
    for (int i = 0; i < n_armas; i++)
        bolsillo_armas[i].mostrar();
}

int Mochila::buscar_consumible(const char* nombre) {
    char nombre_item_consumible[30];
    for (int i = 0; i < n_consumibles; i++) {
        bolsillo_consumibles[i].GetNombre(nombre_item_consumible);
        if (strcmp(nombre_item_consumible, nombre) == 0) {
            if (not bolsillo_consumibles[i].IsEquipadoQ()) {
                bolsillo_consumibles[i].SetEquipadoQ(true);
                return bolsillo_consumibles[i].GetModificador_hp();
            } else
                return 0;
        }
    }
    return -1;
}

int Mochila::buscar_consumible(int indice) {
    if (not bolsillo_consumibles[indice].IsEquipadoQ()) {
        bolsillo_consumibles[indice].SetEquipadoQ(true);
        return bolsillo_consumibles[indice].GetModificador_hp();
    } else
        return 0;
}

int Mochila::buscar_arma(const char* nombre) {
    char nombre_item_arma[30];
    for (int i = 0; i < n_armas; i++) {
        bolsillo_armas[i].GetNombre(nombre_item_arma);
        if (strcmp(nombre_item_arma, nombre) == 0) {
            if (not bolsillo_armas[i].IsEquipadoQ()) {
                bolsillo_armas[i].SetEquipadoQ(true);
                return bolsillo_armas[i].GetModificador_ataque();
            } else
                return 0;
        }
    }
    return -1;
}

int Mochila::buscar_arma(int indice) {
    if (not bolsillo_armas[indice].IsEquipadoQ()) {
        bolsillo_armas[indice].SetEquipadoQ(true);
        return bolsillo_armas[indice].GetModificador_ataque();
    } else
        return 0;
}

int Mochila::buscar_armadura(const char* nombre) {
    char nombre_item_armadura[30];
    for (int i = 0; i < n_armaduras; i++) {
        bolsillo_armaduras[i].GetNombre(nombre_item_armadura);
        if (strcmp(nombre_item_armadura, nombre) == 0) {
            if (not bolsillo_armaduras[i].IsEquipadoQ()) {
                bolsillo_armaduras[i].SetEquipadoQ(true);
                return bolsillo_armaduras[i].GetModificador_defensa();
            } else
                return 0;
        }
    }
    return -1;
}

int Mochila::buscar_armadura(int indice) {
    if (not bolsillo_armaduras[indice].IsEquipadoQ()) {
        bolsillo_armaduras[indice].SetEquipadoQ(true);
        return bolsillo_armaduras[indice].GetModificador_defensa();
    } else
        return 0;
}

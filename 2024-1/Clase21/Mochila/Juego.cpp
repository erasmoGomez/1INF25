/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Juego.cpp
 * Author: Erasmo G. Montoya
 * 
 * Created on May 27, 2024, 5:58 PM
 */
#include "Utils.hpp"
#include "Juego.hpp"
using namespace std;

Juego::Juego() {
}

Juego::Juego(const Juego& orig) {
}

Juego::~Juego() {
}

void Juego::carga_items() {
    ifstream input("items.csv", ios::in);
    char tipo[20], c;
    int n_heroe;
    while(true){
        input.getline(tipo, 20, ',');
        if(input.eof())break;
        input>>n_heroe>>c;
        heroes[n_heroe-1].agregar_mochila(input, tipo);
    }
}

void jugar() {
}
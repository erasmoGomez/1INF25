/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Arma.cpp
 * Author: hecto
 * 
 * Created on May 14, 2025, 5:39 PM
 */

#include "Arma.hpp"

Arma::Arma() {
}

Arma::Arma(const Arma& orig) {
}

Arma::~Arma() {
}

void Arma::leer(ifstream&input){
    //Llama a la clase Padre y su metodo de lectura
    Item::leer(input);
    //147
    //Proceso de lectura de la clase hija
    input>>modificador_poder;
    input.get();
}
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Furgon.cpp
 * Author: Erasmo G. Montoya
 * 
 * Created on June 12, 2024, 7:30 AM
 */

#include "Furgon.hpp"

Furgon::Furgon() {
    filas = 0;
    puertas = 0;
}

Furgon::Furgon(const Furgon& orig) {
}

Furgon::~Furgon() {
}

void Furgon::lee(ifstream& input){
    char c;
    Vehiculo::lee(input);
    input>>filas>>c>>puertas;
}
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Camion.cpp
 * Author: Erasmo G. Montoya
 * 
 * Created on June 12, 2024, 7:29 AM
 */

#include "Camion.hpp"

Camion::Camion() {
    eje = 0;
    llantas = 0;
}

Camion::Camion(const Camion& orig) {
}

Camion::~Camion() {
}

void Camion::lee(ifstream& input){
    char c;
    Vehiculo::lee(input);
    input>>eje>>c>>llantas;
}


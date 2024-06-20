/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Vehiculo.cpp
 * Author: Erasmo G. Montoya
 * 
 * Created on June 12, 2024, 7:25 AM
 */

#include "Vehiculo.hpp"
#include "Camion.hpp"
#include "Utils.hpp"
using namespace std;
Vehiculo::Vehiculo() {
    cliente = 0;
    placa = nullptr;
    maxcarga = actcarga = 0;
    ped = nullptr;
}

Vehiculo::Vehiculo(const Vehiculo& orig) {
}

Vehiculo::~Vehiculo() {
}

void Vehiculo::lee(ifstream& input){
    char c, buffer_placa[8];
    input>>cliente>>c;
    input.getline(buffer_placa, 8, ',');
    input>>maxcarga>>c;
    setPlaca(buffer_placa);
}

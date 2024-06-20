/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LVehiculos.cpp
 * Author: Erasmo G. Montoya
 * 
 * Created on June 12, 2024, 7:38 AM
 */

#include "LVehiculos.hpp"

LVehiculos::LVehiculos() {
    lini = nullptr;
    lfin = nullptr;
}

LVehiculos::LVehiculos(const LVehiculos& orig) {
}

LVehiculos::~LVehiculos() {
}

void LVehiculos::lee_inserta(char tipo, ifstream&input){
    class NodoLista* nuevo;
    Vehiculo* vehiculo;
    if(tipo == 'F')
        vehiculo = new class Furgon;
    else if (tipo == 'C')
        vehiculo = new class Camion;
    vehiculo.lee(input);
    nuevo->unidad = vehiculo;
}
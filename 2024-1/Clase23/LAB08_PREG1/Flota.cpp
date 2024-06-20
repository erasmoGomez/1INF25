/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Flota.cpp
 * Author: Erasmo G. Montoya
 * 
 * Created on June 12, 2024, 7:42 AM
 */

#include "Flota.hpp"
#include "Utils.hpp"
using namespace std;
Flota::Flota() {
}

Flota::Flota(const Flota& orig) {
}

Flota::~Flota() {
}

Flota::cargarflota(){
    ifstream input("Vehiculos.csv", ios::in);
    char tipo_vehiculo;
    //F,79464412,K0D-676,300,1,3
    while(true){
        input>>tipo_vehiculo;
        if(input.eof())break;
        input.get();
        lista.lee_inserta(tipo_vehiculo, input);
    }
}
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "funciones.hpp"
#include "sobrecargas.hpp"

void leer_conductores(ifstream& input, struct Conductor* conductores, int& n){
    while(true){ // Leo todos los conductores
        //struct Conductor c;
        input>>conductores[n]; //Leo un conductor
        if(input.eof())break;
        n++;
    }
}
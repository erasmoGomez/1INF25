/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: hecto
 *
 * Created on March 26, 2025, 3:40 PM
 */

#include "AperturaDeArchivos.h"
#include "funciones.hpp"
/*
 * 
 */
int main(int argc, char** argv) {
    ifstream arch_conductores;
    AperturaDeUnArchivoDeTextosParaLeer(arch_conductores, "conductores.csv");
    struct Conductor conductores[MAX_CONDUCTORES];
    int n_conductores = 0;
    leer_conductores(arch_conductores, conductores, n_conductores);
    
    return 0;
}


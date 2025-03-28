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
#include "sobrecargas.hpp"

/*
 * 
 */
int main(int argc, char** argv) {
    Papeleta p;
    //cout<<p;
    
    ifstream input;
    AperturaDeUnArchivoDeTextosParaLeer(input, "papeletas.csv");
    input>>p;
    return 0;
}


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
    Papeleta p, p2, p3;
    Conductor c;
    //cout<<p;
    
    ifstream input, input_constructores;
    ofstream output;
    AperturaDeUnArchivoDeTextosParaLeer(input, "papeletas.csv");
    AperturaDeUnArchivoDeTextosParaEscribir(output, "reporte.txt");
    AperturaDeUnArchivoDeTextosParaLeer(input_constructores, "constructores.csv");
    input>>p;
    input>>p2;
    input>>p3;
    cout<<p;
    output<<p;
    input_constructores>>c;
    cout<<c;
    output<<c;
    cout<<c.dni<<endl;
    cout<<(c<12345679);
    cout<<endl;
    cout<<(c<11222212);
    c+=p;
    c+=p2;
    c+=p3;
    cout<<c;
    output<<c;
    return 0;
}


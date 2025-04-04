/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: hecto
 *
 * Created on April 1, 2025, 6:34 PM
 */

#include "funciones.hpp"

/*
 * 
 */
int main(int argc, char** argv) {
    int *datos, n_datos = 0;
    leer_datos_exactos(datos,n_datos,"datos.txt");
    for(int i=0; i<n_datos; i++)
        cout<<datos[i]<<endl;
    return 0;
}


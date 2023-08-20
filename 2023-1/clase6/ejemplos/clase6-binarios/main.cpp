/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: erasmog
 *
 * Created on April 11, 2023, 8:01 AM
 */


#include "funciones.hpp"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int indice;
    char nombre[60];
//    crear_archivo_binario("personas.txt", "in.bin");
//    leer_archivo_binario("in.bin");
//    acceso_directo_datos("in.bin", 10);
//    indice = busqueda_datos_binario("in.bin");
    cout<<sizeof(const char)*60<<endl;
    cout<<sizeof(nombre)<<endl;
    cout<<sizeof(char *)<<endl;
    cout<<sizeof(int *)<<endl;
    return 0;
}


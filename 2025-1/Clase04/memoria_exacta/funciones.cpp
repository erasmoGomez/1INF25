/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "funciones.hpp"

void leer_datos_exactos(int*& datos, int &n_datos, const char* nombre_archivo){
    ifstream arch(nombre_archivo, ios::in);
    
    int buffer[100];
    int dato;
    while(true){
        arch>>dato;
        if(arch.eof())break;
        buffer[n_datos] = dato;
        n_datos++;
    }
    datos = new int[n_datos];
    
    for(int i=0; i<n_datos;i++)
        datos[i] = buffer[i];
}
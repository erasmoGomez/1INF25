/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   plantillas.hpp
 * Author: erasmog
 *
 * Created on April 19, 2023, 8:22 AM
 */

#ifndef PLANTILLAS_HPP
#define PLANTILLAS_HPP

#include "persona.hpp"
#include "funciones.hpp"
#include "funciones_sobrecargadas.hpp"
template <typename T>
void leer_datos(T *a, int &n, const char* nombre_archivo){
    ifstream arch(nombre_archivo, ios::in);
    if (not arch.is_open()){
        cout<< "No se pudo abrir el archivo: "<<nombre_archivo<<endl;
        exit(1);
    }
    n = 0;
    while(true){
        arch>>a[n];
        if(arch.eof())break;
        n++;
    }
}
#endif /* PLANTILLAS_HPP */


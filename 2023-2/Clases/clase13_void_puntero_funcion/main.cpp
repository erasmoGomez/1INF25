/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Erasmo G. Montoya
 *
 * Created on September 20, 2023, 7:15 AM
 */

#include <cstdlib>
#include <iostream>
#include "funciones_genericas.hpp"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    void *personal;
    int n_datos;
    cout<<"DATOS LEIDOS"<<endl;
    leer_datos_personal(personal, n_datos);
    imprimir_datos(personal, n_datos);
    cout<<"---------------------------------------------"<<endl;
    cout<<"DATOS ORDENADOS QSORT"<<endl;
    qsort(personal, n_datos, sizeof(void*),funcion_comparacion_nombres);
    imprimir_datos(personal, n_datos);
    cout<<"---------------------------------------------"<<endl;
    cout<<"DATOS ORDENANOS GENERICO CODIGO"<<endl;
    ordenar_personal(personal,0,n_datos-1,funcion_comparacion_propia_codigos);
    imprimir_datos(personal, n_datos);
    cout<<"---------------------------------------------"<<endl;
    cout<<"DATOS ORDENANOS GENERICO SUELDO"<<endl;
    ordenar_personal(personal,0,n_datos-1,funcion_comparacion_propia_sueldos);
    imprimir_datos(personal, n_datos);
    cout<<"---------------------------------------------"<<endl;
    return 0;
}


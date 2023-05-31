/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: erasmog
 *
 * Created on May 30, 2023, 6:25 AM
 */

#include "auxiliar.hpp"
#include "funciones.hpp"

/*
 * 
 */
int main(int argc, char** argv) {
    void *personal;
    int np = 0;

    leer_datos_void(personal, np);
    imprimir_datos_void(personal, np);
    ordenar_chevere(personal, 0, np - 1, cmp_codigo_void);
    cout<<"imprimir ordenado"<<endl;
    imprimir_datos_void(personal, np);

    return 0;
}


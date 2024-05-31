/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Erasmo G. Montoya
 *
 * Created on May 29, 2024, 8:23 AM
 */

#include "ClaseDerivada.hpp"
#include "ClaseDerivada2.hpp"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    //Requisitos para polimorfismo
    //1. Puntero a la clase base
    //2. Metodo polimorficos
    
    
//    ClaseBase *ptr_base;
//    ClaseBase base;
//    ClaseDerivada derivada1;
//    
//    ptr_base = &derivada1;
//    
//    //derivada1.mostrar();
//    ptr_base->mostrar();
//    base.mostrar();
    ClaseDerivada d1, d2;
    ClaseDerivada2 dd1, dd2;
    ClaseDerivada d3;
    
    d1.SetD(1);
    d2.SetB(2);
    dd1.SetD2(3);
    dd2.SetD2(4);
    d3.SetD(5);
    ClaseBase *arr_clases_base[5]; //5 punteros a la clase base
    
    arr_clases_base[0] = &d1;
    arr_clases_base[1] = &d2;
    arr_clases_base[2] = &dd1;
    arr_clases_base[3] = &dd2;
    arr_clases_base[4] = &d3;
    
    for(int i = 0; i< 5;i++)
        arr_clases_base[i]->mostrar();
    return 0;
}


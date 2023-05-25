/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: erasmog
 *
 * Created on May 23, 2023, 7:48 AM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

#include "funciones_auxiliares.hpp"
/*
 * 
 */
int main(int argc, char** argv) {
//    cout<<suma(3,5)<<endl;
//    cout<<resta(5,3)<<endl;
    
//    int (*ptr_funcion)(int,int);
//    
//    ptr_funcion = suma;
//    
//    cout<<ptr_funcion(10,2)<<endl;
    
//    int (*ptr_funcion_arreglo[3])(int, int) = {suma,resta,mult};
//    cout<<ptr_funcion_arreglo[2](5,8)<<endl;
//    int c;
//   ptr_funcion_arreglo[2](5,8);
//    void* (*ptr_funcion_arreglo_void[2])(void*) = {hace_algo_1, hace_algo_2};
    int (*ptr)(int,int);
    ptr = mult;
    cout<<operacion(10,5,ptr)<<endl;
    cout<<operacion(10,5,mult)<<endl;
    return 0;
}


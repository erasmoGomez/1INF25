/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "funciones_auxiliares.hpp"

int suma(int a, int b){
    return a+b;
}

int resta(int a, int b){
    return a-b;
}

int mult(int a, int b){
    return a*b;
}

void * hace_algo_1(void* a){
    return a;
}

void * hace_algo_2(void* a){
    return a;
}

int operacion(int a, int b, int (*ptr_funcion)(int, int)){
    int result;
    result = ptr_funcion(a,b);
    return result;
}
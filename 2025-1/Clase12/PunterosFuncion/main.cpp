/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Erasmo Gomez
 * Description: 
 * Created on April 23, 2025, 4:31 PM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

/*
 * 
 */
double suma(int x, int y){
    return x+y;
}

double dividir(int x, int y){
    return (double)x/y;
}

double multiplicar(int x, int y){
    return (double)x*y;
}

double calcular_promedio(int x, int y){
    return (double)(x+y)/2;
}

double operacion_generica(int x, int y, double(*funcion_generica)(int, int)){
    return funcion_generica(x, y);
}

int main(int argc, char** argv) {
    int x = 6, y = 10;
    cout<<suma(x,y)<<endl;
    
    double (*ptr_funcion)(int, int);
    
    ptr_funcion = suma;
//    cout<<suma<<endl;
//    cout<<ptr_funcion<<endl;
    cout<<ptr_funcion(x,y)<<endl;
    ptr_funcion = calcular_promedio;
    
    double (*arr_ptr_funcion[3])(int, int);
    arr_ptr_funcion[0] = dividir;
    arr_ptr_funcion[1] = suma;
    arr_ptr_funcion[2] = calcular_promedio;
    
    for(int i=0; i<3; i++){
        cout<<"El resultado de la operacion: "<< i+1<<" es ";
        cout<<arr_ptr_funcion[i](x,y)<<endl;
    }
    
    cout<<"Funcion generica: "<< operacion_generica(x, y, suma)<<endl;
    cout<<"Funcion generica: "<< operacion_generica(x, y, dividir)<<endl;
    cout<<"Funcion generica: "<< operacion_generica(x, y, calcular_promedio)<<endl;

    return 0;
}


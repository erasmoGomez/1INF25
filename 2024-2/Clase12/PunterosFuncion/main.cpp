/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Erasmo G. Montoya
 *
 * Created on September 24, 2024, 4:57 PM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

/*
 * 
 */

double dividir(int x, int y) {
    return (double) x / y;
}

double multiplicar(int x, int y) {
    return (double)x * y;
}

double calcular_promedio(int x, int y){
    return (double)(x+y)/2;
}

int corregir(int x, double y){
    return (x+y)/2;
}

//Generica

double operacion_generica(int x,int y, double(*funcion)(int, int) ){
    return funcion(x,y);
}

int main(int argc, char** argv) {
    int x = 6, y = 4;
    double (*ptr_funcion)(int, int);
    ptr_funcion = multiplicar;
    cout<<multiplicar(x,y)<<endl;
    cout<<ptr_funcion(x,y)<<endl;
    ptr_funcion = calcular_promedio;
    cout<<ptr_funcion(x,y)<<endl;
    
    double (*arr_ptr_funcion[3])(int, int);
    arr_ptr_funcion[0] = dividir;
    arr_ptr_funcion[1] = multiplicar;
    arr_ptr_funcion[2] = calcular_promedio;
    for(int i=0; i<3;i++)
        cout<<"Resultado de la funcion: "<< arr_ptr_funcion[i](x,y)<<endl;
    
    cout<<"Funcion Generica: "<<operacion_generica(x,y,calcular_promedio)<<endl;
    cout<<"Funcion Generica: "<<operacion_generica(x,y,multiplicar)<<endl;
    cout<<"Funcion Generica: "<<operacion_generica(x,y,dividir)<<endl;
    //cout<<"Funcion Generica: "<<operacion_generica(x,y,corregir)<<endl;
    
    
    return 0;
}


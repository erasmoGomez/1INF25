/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Erasmo G. Montoya
 *
 * Created on April 23, 2024, 9:25 AM
 */

#include <iostream>
#include <math.h>
using namespace std;

/*
 * 
 */

double suma (int a,int b){
    return double(a+b);
}

double division (int a,int b){
    return double(a)/b;
}

double division2 (int a,int b, int c){
    return double(a)/b;
}

double promedio (int a,int b){
    return (double)(a+b)/2;
}

double f (int a,int b){
    return b + sqrt(a);
}

double funcion(int a, int b, double(*generico)(int, int)){
    return generico(a,b);
}

int main(int argc, char** argv) {
    int x = 9, y =7;
    //division(x,y);
    double(*pf)(int, int);
    double (*arr_pf[3])(int, int){division, promedio, f};
    pf = division;
    cout<<"Hola soy division: "<<pf(x,y)<<endl;
    pf = f;
    cout<<"Hola soy f: "<<pf(x,y)<<endl;
    cout<<"Hola soy promedio: "<<arr_pf[1](x,y)<<endl;
    double z;
    z = funcion(x,y,division);
    
    cout<<"Estoy llamando desde otra funcion: "<<z<<endl;
    
    z = funcion(x,y,f);
    
    cout<<"Estoy llamando desde otra funcion: "<<z<<endl;
    
    return 0;
}


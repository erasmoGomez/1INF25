/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "funciones.hpp"

void imprimir_fecha(int dd, int mm, int aa){
    cout<<setfill('0');
    cout<<setw(2)<<dd<<'/'<<setw(2)<<mm<<'/'<<setw(4)<<aa<<endl;
    cout<<setfill(' ');
}

int f(int a){
    return a+10;
}

int f(int a, int b){
    return a+b;
}
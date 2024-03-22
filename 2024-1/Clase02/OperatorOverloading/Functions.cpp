/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "Functions.hpp"

int add(int a, int b){
    return  a + b;
}

void add_headers(){
    cout<<setw(ANCHO/2)<<right<<"Mi persona favorita"<<endl;
    cout<<left<<setw(ANCHO/3)<<"DNI"<<left<<setw(ANCHO/3)<<"NOMBRE";
    cout<<left<<setw(ANCHO/3)<<"TALLA"<<endl;
}
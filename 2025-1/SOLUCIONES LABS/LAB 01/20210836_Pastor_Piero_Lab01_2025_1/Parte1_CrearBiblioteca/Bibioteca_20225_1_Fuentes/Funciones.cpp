/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Funciones.cpp
 * Author: piero
 * 
 * Created on 14 de abril de 2025, 11:24 PM
 */

#include "Funciones.h"

int compare(CadenaDeCaracteres &cad, char *cadena){
    if(cad.cadena == nullptr or cadena == nullptr) return 0;
    int lcad=cad.longitud, lcadena=strlen(cadena), n;
    n = (lcad > lcadena)?lcad:lcadena;
    char c1, c2;
    for(int i=0; i < n; i++){
        if(i < lcad) c1 = ('z' >= cad.cadena[i]) >= 'a'?(cad.cadena[i]-32):(cad.cadena[i]);
        else c1 = 0;
        if(i < lcadena) c2 = ('z' >= cadena[i]) >= 'a'?(cadena[i]-32):(cadena[i]);
        else c2 = 0;
        if(c1 != c2) return c1 - c2;
    }
    return 0;
}
int compare(CadenaDeCaracteres &cad1, CadenaDeCaracteres &cad2){
    return compare(cad1, cad2.cadena);
}
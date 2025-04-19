/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Sobrecargas.cpp
 * Author: piero
 * 
 * Created on 14 de abril de 2025, 11:21 PM
 */
#include "Sobrecargas.h"

void operator !(CadenaDeCaracteres &cad){
    cad.cadena = nullptr; //Inicializa en null
    cad.capacidad = 0; //Inicializa capacidad y longitud en cero
    cad.longitud = 0;
}

void operator <=(CadenaDeCaracteres &cad, char* cadena){
    if(cadena == nullptr) return;
    int len=strlen(cadena)+1;
    if(not (cad.cadena == nullptr or cad.capacidad == 0) and cad.capacidad < len 
            and cad.cadena != cadena) delete cad.cadena; //Si no son iguales, y no entra, entonces delete
    if(cad.capacidad < len and cad.cadena != cadena) cad <= len; //Si no son iguales, y no entra, hace new
    strcpy(cad.cadena, cadena); //Copia
    cad.longitud = len-1; //Asigna longitud
}
void operator <=(CadenaDeCaracteres &cad, int n){
    cad.cadena = new char[cad.capacidad = n]{}; //Hace new
    cad.longitud = 0; //Longitud vacia
}
void operator <=(CadenaDeCaracteres &cad1, CadenaDeCaracteres &cad2){
    cad1 <= cad2.cadena; //Llama a la superior
}

bool operator +=(CadenaDeCaracteres &cad, char* cadena){
    if(cadena == nullptr or cad.capacidad == 0 or cad.cadena == nullptr) return false;
    int len=strlen(cadena)+1;
    bool equal=false;
    if(cad.capacidad < len+cad.longitud) {
        char buff[cad.longitud+1]; //Crea buffer
        strcpy(buff, cad.cadena); //Guarda por si acaso
        if(cad.cadena != cadena) delete cad.cadena; //Si no son iguales delete
        else equal=true; //Si lo son, espera para hacer delete
        cad <= len+cad.longitud; //Hace new
        strcpy(cad.cadena, buff); //Copia el buffer
    }
    strcat(cad.cadena, cadena); //Concatena
    cad.longitud = strlen(cad.cadena); //
    if(equal) delete cadena;
    return true;
}

bool operator +=(CadenaDeCaracteres &cad1, CadenaDeCaracteres &cad2){
    bool aux = cad1 += cad2.cadena;
    return aux;
}

bool operator ==(CadenaDeCaracteres &cad, char* cadena){
    return compare(cad, cadena) == 0;
}
bool operator <(CadenaDeCaracteres &cad, char* cadena){
    return compare(cad, cadena) < 0;
}
bool operator >(CadenaDeCaracteres &cad, char* cadena){
    return compare(cad, cadena) > 0;
}

bool operator ==(CadenaDeCaracteres &cad1, CadenaDeCaracteres &cad2){
    return compare(cad1, cad2) == 0;
}
bool operator <(CadenaDeCaracteres &cad1, CadenaDeCaracteres &cad2){
    return compare(cad1, cad2) < 0;
}
bool operator >(CadenaDeCaracteres &cad1, CadenaDeCaracteres &cad2){
    return compare(cad1, cad2) > 0;
}

int operator >> (ifstream &arch, CadenaDeCaracteres &cad){
    char buff[500];
    arch >> buff;
    if(arch.eof()) return 1;
    if(buff[0] <'A' or buff[0] >'z') return -1;
    cad <= buff;
    return 0;
}

void operator &&(CadenaDeCaracteres &cad1, CadenaDeCaracteres &cad2){
    CadenaDeCaracteres aux;
    !aux;
    aux <= cad1;
    cad1 <= cad2;
    cad2 <= aux;
    return;
}

ofstream& operator << (ofstream &arch, CadenaDeCaracteres &cad){
    arch << cad.cadena;
    return arch;
}


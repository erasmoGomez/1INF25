/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   EquipoArbol.cpp
 * Author: hecto
 * 
 * Created on June 4, 2025, 5:32 PM
 */

#include "EquipoArbol.hpp"
#include "Heroe.hpp"

EquipoArbol::EquipoArbol() {
    equipo = nullptr;
}

EquipoArbol::EquipoArbol(const EquipoArbol& orig) {
}

EquipoArbol::~EquipoArbol() {
}


void EquipoArbol::crear(const char*nombre_archivo){
    ifstream input(nombre_archivo, ios::in);
    class Heroe h;
    char buffer[50];
    while(true){
        input>>h;
        h.getNombre(buffer);
        if(input.eof())break;
        insertar_recursivo(equipo, h);
    }
}

void EquipoArbol::insertar_recursivo(class NodoArbol* equipo, h){
    if(equipo == nullptr){
        equipo = new class NodoArbol;
        equipo.dato = h;
    }
}
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
        cout<<buffer<<endl;
        if(input.eof())break;
        insertar_recursivo(equipo, h);
    }
}

void EquipoArbol::insertar_recursivo(class NodoArbol* &equipo, const class Heroe h){
    if(equipo == nullptr){
        equipo = new class NodoArbol;
        equipo->dato = h; // Llama a la sobrecarga del operador =
        return;
    }
    //ABB -> Arbol Binario de Busqueda
    //Quiero insertar en la derecha o a la izq
    if(equipo->dato > h)//Llama a la sobrecarga del operador >
        insertar_recursivo(equipo->izq, h);
    else
        insertar_recursivo(equipo->der, h);
}

void EquipoArbol::mostrar_en_orden_recursivo(class NodoArbol*_equipo, ofstream& output){
    if(_equipo){
        mostrar_en_orden_recursivo(_equipo->izq, output); //Izq
        output<<_equipo->dato; // raiz
        mostrar_en_orden_recursivo(_equipo->der, output); //Der
    }
}

void EquipoArbol::mostrar_post_orden_recursivo(class NodoArbol*_equipo, ofstream& output){
    if(_equipo){
        mostrar_post_orden_recursivo(_equipo->izq, output); //Izq
        mostrar_post_orden_recursivo(_equipo->der, output); //Der
        output<<_equipo->dato; // raiz
    }
}

void EquipoArbol::mostrar_en_orden(const char* nombre_archivo){
    ofstream output(nombre_archivo, ios::out);
    mostrar_en_orden_recursivo(equipo, output);
}

void EquipoArbol::mostrar_post_orden(const char* nombre_archivo){
    ofstream output(nombre_archivo, ios::out);
    mostrar_post_orden_recursivo(equipo, output);
}
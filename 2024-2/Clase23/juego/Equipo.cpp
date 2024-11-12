/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Equipo.cpp
 * Author: Erasmo G. Montoya
 * 
 * Created on November 5, 2024, 5:24 PM
 */

#include "Equipo.hpp"

Equipo::Equipo() {
    equipo = nullptr;
}

Equipo::Equipo(const Equipo& orig) {
}

Equipo::~Equipo() {
}

void Equipo::crear(const char* nombre_archivo){
    ifstream input(nombre_archivo, ios::in);
    char buffer[50];
    class Heroe h;
    while(true){
        input>>h;
        h.getNombre(buffer);
        cout<<buffer<<endl;
        if(input.eof())break;
        insertar_recursivo(equipo, h);
    }
}

void Equipo::insertar_recursivo(class NodoArbol* &equipo, const class Heroe& h){
    if (equipo == nullptr){
        equipo = new class NodoArbol;
        equipo->dato = h;
        return;
    }
    if(equipo->dato > h)
        insertar_recursivo(equipo->izq, h);
    else
        insertar_recursivo(equipo->der, h);
}

void Equipo::mostrar_en_orden(const char* nombre_archivo){
    ofstream output(nombre_archivo, ios::out);
    mostrar_en_orden_recursivo(equipo, output);
}

void Equipo::mostrar_post_orden(const char* nombre_archivo){
    ofstream output(nombre_archivo, ios::out);
    mostrar_post_orden_recursivo(equipo, output);
}

void Equipo::mostrar_en_orden_recursivo(class NodoArbol* equipo, ofstream &output){
    if(equipo){
        mostrar_en_orden_recursivo(equipo->izq,output);
        output<<equipo->dato;
        mostrar_en_orden_recursivo(equipo->der,output);
    }
}

void Equipo::mostrar_post_orden_recursivo(class NodoArbol* equipo, ofstream &output){
    if(equipo){
        mostrar_post_orden_recursivo(equipo->izq,output);
        mostrar_post_orden_recursivo(equipo->der,output);
        output<<equipo->dato;
    }
}
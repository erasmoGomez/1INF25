/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Equipo.cpp
 * Author: hecto
 * 
 * Created on June 4, 2025, 4:53 PM
 */

#include <valarray>

#include "Equipo.hpp"

Equipo::Equipo() {
    lista = nullptr;
}

Equipo::Equipo(const Equipo& orig) {
}

Equipo::~Equipo() {
}

void Equipo::crear(const char*nombre_archivo){
    ifstream input(nombre_archivo, ios::in);
    while(true){
        class Heroe h;
        input>>h;
        if(input.eof())break;
        insertar(h);
    }
}

void Equipo::insertar(const class Heroe&h){
    Nodo* recorrido = lista;
    Nodo* anterior = nullptr;
    Nodo* nuevo;
    
    nuevo = new class Nodo;
    nuevo->dato = h; // Sobrecarga del operador = en Heroe
    while(recorrido){
        if(recorrido->dato>h)break; // h1 > h
        anterior = recorrido;
        recorrido = recorrido->sig;
    }
    nuevo->sig = recorrido;
    if(anterior!=nullptr)
        anterior->sig = nuevo;
    else
        lista = nuevo;
}

void Equipo::imprimir(const char*nombre_archivo){
    ofstream output(nombre_archivo, ios::out);
    imprimir_recursivo(lista, output);
}

void Equipo::imprimir_recursivo(class Nodo* ptr, ofstream& output){
    if(ptr == nullptr) return;
    output<<ptr->dato;
    imprimir_recursivo(ptr->sig, output);
}
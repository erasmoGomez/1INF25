/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Lista.cpp
 * Author: Erasmo G. Montoya
 * 
 * Created on November 4, 2024, 5:33 PM
 */

#include "Lista.hpp"

Lista::Lista() {
    lista = nullptr;
}

Lista::Lista(const Lista& orig) {
}

Lista::~Lista() {
}

void Lista::crear(const char*nombre_archivo){
    ifstream input(nombre_archivo, ios::in);
    
    while(true){
        class Heroe h;
        input>>h;
        if ( input.eof())break;
        insertar(h);
    }
}

void Lista::insertar(const class Heroe& h){
    Nodo* recorrido = lista;
    Nodo* anterior = nullptr;
    Nodo* nuevo;
    
    nuevo = new class Nodo;
    nuevo->dato = h; //Sobrecarga de operador = en Heroe
    while(recorrido){
        if(recorrido->dato>h) break; //Sobrecarga del operador >
        anterior = recorrido;
        recorrido = recorrido->sig;
    }
    nuevo->sig = recorrido;
    if(anterior!=nullptr)
        anterior->sig = nuevo;
    else
        lista = nuevo;
}

void Lista::imprimir(const char* nombre_archivo){
    ofstream out(nombre_archivo, ios::out);
    imprimir_recursivo(lista, out);
}

void Lista::imprimir_recursivo(class Nodo*ptr, ofstream&out){
    if(ptr == nullptr) return;
    out << ptr->dato;
    imprimir_recursivo(ptr->sig, out);
}
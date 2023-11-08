/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Arbol.cpp
 * Author: ASUS
 * 
 * Created on November 7, 2023, 12:59 AM
 */

#include "Arbol.hpp"

Arbol::Arbol() {
    arbol = nullptr;
}

Arbol::Arbol(const Arbol& orig) {
}

Arbol::~Arbol() {
}

void Arbol::insertar_recursivo(Node* &arbol,const class Hero& h) {
    if (arbol == nullptr) {
        arbol = new class Node;
        arbol->dato = h;
        return;
    }
    if (arbol->dato > h)
        insertar_recursivo(arbol->izq, h);
    else
        insertar_recursivo(arbol->der, h);
}

void Arbol::crear(const char* filename) {
    ifstream input(filename, ios::in);
    if(not input.is_open()){
        cout<<"Fue"<<endl;
        exit(1);
    }
    class Hero dato;
    while (true) {
        input>>dato;
        if (input.eof())break;
        insertar_recursivo(arbol, dato);
    }
}

void Arbol::en_orden_recursivo(Node* arbol) {
    if (arbol) {
        en_orden_recursivo(arbol->izq);
        cout << arbol->dato << endl;
        en_orden_recursivo(arbol->der);
    }
}

void Arbol::en_orden() {
    en_orden_recursivo(arbol);
    cout << endl;
}

class Hero Arbol::buscar_recursivo(Node* arbol, const char*name) {
    class Hero h;
    char buffer[10];
    h.SetCode(-1);
    if(arbol==nullptr) return h;
    if(arbol->dato == name) return arbol->dato;
    if(arbol->dato > name) 
        return buscar_recursivo(arbol->izq, name);
    else
        return buscar_recursivo(arbol->der, name);
}

class Hero Arbol::buscar(const char* name) {
    return buscar_recursivo(arbol, name);
}
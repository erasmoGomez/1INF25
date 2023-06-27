/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "arbol.hpp"

Arbol::Arbol() {
    arbol = nullptr;
}

Arbol::~Arbol() {
    //Delete all the nodes
    eliminar(arbol);
}

void Arbol::eliminar(class Nodo * arbol) {
    if (arbol) {
        eliminar(arbol->izq);
        eliminar(arbol->der);
        delete arbol;
    }
}

void Arbol::crear(const char* nombre_archivo) {
    ifstream arch(nombre_archivo, ios::in);
    Persona dato;
    while (true) {
        arch>>dato;
        if (arch.eof()) break;
        insertar_restrictivo(arbol, dato);
    }
}

void Arbol::insertar_restrictivo(class Nodo *&arbol, const class Persona&dato) {
    if (arbol == nullptr) {
        arbol = new class Nodo;
        arbol->dato = dato;
        return;
    }
    if (arbol->dato > dato)
        //insertar izq
        insertar_restrictivo(arbol->izq, dato);
    else
        //insertar der
        insertar_restrictivo(arbol->der, dato);
}

void Arbol::insertar(const class Persona& dato) {
    insertar_restrictivo(this->arbol, dato);
}

void Arbol::recorrer_en_pre_orden_restrictivo(class Nodo * arbol) {
    if(arbol){
        cout<<arbol->dato;
        recorrer_en_pre_orden_restrictivo(arbol->izq);
        recorrer_en_pre_orden_restrictivo(arbol->der);
    }
}

void Arbol::recorrer_en_orden_restrictivo(class Nodo * arbol) {
    if(arbol){
        recorrer_en_orden_restrictivo(arbol->izq);
        cout<<arbol->dato;
        recorrer_en_orden_restrictivo(arbol->der);
    }
}

void Arbol::recorrer_en_pre_orden() {
    recorrer_en_pre_orden_restrictivo(arbol);
    cout << endl;
}

void Arbol::recorrer_en_orden() {
    recorrer_en_orden_restrictivo(arbol);
    cout << endl;
}

class Persona Arbol::buscar_restrictivo(class Nodo *arbol, int dni){
    class Persona p;
    int dni_nodo;
    p.SetDni(-1); // No encontrado
    if(arbol == nullptr) return p;
    if(arbol->dato==dni) return arbol->dato; // lo encontre
    dni_nodo = arbol->dato.GetDni();
    if(dni_nodo>dni)
        return buscar_restrictivo(arbol->izq, dni);
    else
        return buscar_restrictivo(arbol->der, dni);
}

class Persona Arbol::buscar(int dni){
    return buscar_restrictivo(arbol, dni);
}
//
// Created by Erasmo on 29/10/25.
//

#include "EquipoLista.hpp"

EquipoLista::EquipoLista() {
    lista = nullptr;
}

EquipoLista::EquipoLista(const EquipoLista &orig) {
}

EquipoLista::~EquipoLista() {
}

void EquipoLista::crear(const char * file_name) {
    ifstream input(file_name, ios::in);

    while(true){
        class Heroe h;
        input>>h;
        if(input.eof())break;
        insertar(h);
    }
}

void EquipoLista::insertar(const Heroe & h) {
    class NodoLista* recorrido = lista;
    class NodoLista* anterior = nullptr;
    class NodoLista* nuevo;

    //Crear el nodo nuevo
    nuevo = new class NodoLista;
    nuevo->dato = h; // Llama a la sobrecarga del = q ya se hizo

    while(recorrido){
        if(recorrido->dato > h) break; // h1 > h
        anterior = recorrido;
        recorrido = recorrido->sig;
    }
    nuevo->sig = recorrido;
    if(anterior!=nullptr)
        anterior->sig = nuevo;
    else
        lista = nuevo;
}

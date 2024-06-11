//
// Created by Erasmo on 8/06/24.
//

#include "Equipo.hpp"

Equipo::Equipo() {
    equipo = nullptr;
}

Equipo::~Equipo() {
}

void Equipo::crear(const char *filename) {
    ifstream input(filename, ios::in);
    class Heroe dato;
    char nombre[30];
    while(true){
        input>>dato;
        if(input.eof())break;
        insertar_recursivo(equipo, dato);
    }
}

void Equipo::insertar_recursivo(Nodo* &equipo, const class Heroe &h){
    if(equipo == nullptr){
        equipo = new class Nodo;
        equipo->dato = h;
        return;
    }
    if(equipo->dato > h)
        insertar_recursivo(equipo->izq, h);
    else
        insertar_recursivo(equipo->der, h);
}

void Equipo::mostrar_en_orden_recursivo(Nodo *&equipo){
    if(equipo){
        mostrar_en_orden_recursivo(equipo->izq);
        cout<<equipo->dato;
        mostrar_en_orden_recursivo(equipo->der);
    }
}

void Equipo::mostrar_post_orden_recursivo(Nodo *&equipo){
    if(equipo){
        mostrar_en_orden_recursivo(equipo->izq);
        mostrar_en_orden_recursivo(equipo->der);
        cout<<equipo->dato;
    }
}

void Equipo::mostrar_en_orden(){
    mostrar_en_orden_recursivo(equipo);
    cout<<endl;
}

void Equipo::mostrar_post_orden(){
    mostrar_post_orden_recursivo(equipo);
    cout<<endl;
}
//
// Created by Erasmo on 29/10/25.
//

#include "EquipoArbol.hpp"

EquipoArbol::EquipoArbol() {
    arbol = nullptr;
}

EquipoArbol::EquipoArbol(const EquipoArbol &orig) {
    arbol = orig.arbol;
}

EquipoArbol::~EquipoArbol() {
    delete arbol;
}

void EquipoArbol::crear(const char *file_name) {
    ifstream input(file_name, ios::in);
    class Heroe h;
    while (true) {
        input >> h;
        if (input.eof())break;
        insertar_recursivo(arbol, h); // Tiene que ser private
    }
}

//     (X)
//  (A)   (B) -> X A B C
//(C)
//
//  (A)
//(C)
//
//  (C)
//
//  (B)

void EquipoArbol::insertar_recursivo(NodoArbol *&arbol, const struct Heroe h) {
    if (arbol == nullptr) { // CB: Finalidad es crear la raiz de cada sub arbol en el arbol.
        arbol = new class NodoArbol;
        arbol->dato = h;
        return;
    }
    // ABB -> Arbol Binario de Busqueda.
    // Quiero insertar ya sea a la derecha o a la izq dependiendo de la comparacion
    if (arbol->dato > h)
        insertar_recursivo(arbol->izq, h);
    else
        insertar_recursivo(arbol->der, h);
}

void EquipoArbol::mostrar_en_orden(const char * file_name) {
    ofstream output(file_name, ios::out);
    mostrar_en_orden_recursivo(arbol, output);
}

void EquipoArbol::mostrar_post_orden(const char * file_name) {
    ofstream output(file_name, ios::out);
    mostrar_post_orden_recursivo(arbol, output);
}

void EquipoArbol::mostrar_en_orden_recursivo(NodoArbol *& _arbol, ofstream &output) {
    // HI R HD
    if(_arbol){
        mostrar_en_orden_recursivo(_arbol->izq, output);
        output<<_arbol->dato; // Raiz
        mostrar_en_orden_recursivo(_arbol->der, output);
    }
}

void EquipoArbol::mostrar_post_orden_recursivo(NodoArbol *& _arbol, ofstream &output) {
    // HI HD R
    if(_arbol){
        mostrar_en_orden_recursivo(_arbol->izq, output);
        mostrar_en_orden_recursivo(_arbol->der, output);
        output<<_arbol->dato; // Raiz
    }
}

void EquipoArbol::mostrar_pre_orden_recursivo(NodoArbol *& _arbol, ofstream &output) {
    // R HI HD
    if(_arbol){
        output<<_arbol->dato; // Raiz
        mostrar_en_orden_recursivo(_arbol->izq, output);
        mostrar_en_orden_recursivo(_arbol->der, output);
    }
}

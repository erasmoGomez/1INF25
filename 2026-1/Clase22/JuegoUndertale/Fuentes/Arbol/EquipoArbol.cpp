//
// Created by erasmo on 6/10/26.
//

#include "EquipoArbol.hpp"

EquipoArbol::EquipoArbol() {
    raiz = nullptr;
}

EquipoArbol::EquipoArbol(const EquipoArbol &orig) {
    raiz = orig.raiz;
}

EquipoArbol::~EquipoArbol() {

}

void EquipoArbol::crear(const char *file_name) {
    ifstream input(file_name, ios::in);
    class Personaje p;
    while (true) {
        input >> p;
        if (input.eof())break;
        insertar_recursivo(raiz, p); // Tiene que ser private
    }
}


void EquipoArbol::insertar_recursivo(NodoArbol *&arbol, const  Personaje p) {
    if (arbol == nullptr) { // CB: Finalidad es crear la raiz de cada sub raiz en el raiz.
        arbol = new class NodoArbol;
        arbol->dato = p;
        return;
    }
    // ABB -> Arbol Binario de Busqueda.
    // Quiero insertar ya sea a la derecha o a la izq dependiendo de la comparacion
    if (arbol->dato > p)
        insertar_recursivo(arbol->izq, p);
    else
        insertar_recursivo(arbol->der, p);
}

void EquipoArbol::mostrar_en_orden(const char * file_name) {
    ofstream output(file_name, ios::out);
    mostrar_en_orden_recursivo(raiz, output);
}

void EquipoArbol::mostrar_post_orden(const char * file_name) {
    ofstream output(file_name, ios::out);
    mostrar_post_orden_recursivo(raiz, output);
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
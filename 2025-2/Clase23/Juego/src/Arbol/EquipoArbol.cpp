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
        insertar_recursivo(arbol, h);
    }
}

void EquipoArbol::insertar_recursivo(NodoArbol *&arbol, const struct Heroe h) {
    if (arbol == nullptr) {
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

void EquipoArbol::mostrar_en_orden_recursivo(NodoArbol *& _arbol, ofstream &output) {
    if(_arbol){
        mostrar_en_orden_recursivo(_arbol->izq, output);
        output<<_arbol->dato; // Raiz
        mostrar_en_orden_recursivo(_arbol->der, output);
    }
}

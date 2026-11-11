//
// Created by erasmo on 11/4/26.
//

#include "EquipoArbol.hpp"

void EquipoArbol::insertar_recursivo(class NodoArbol *&raiz, const class Player player) {
    //caso base
    if (raiz == nullptr) {
        raiz = new class NodoArbol();
        raiz->dato = player;
        return;
    }
    //caso recursivo
    if (raiz->dato>player) {
        insertar_recursivo(raiz->izq,player);
    }
    else {
        insertar_recursivo(raiz->der,player);
    }
}

EquipoArbol::EquipoArbol() {
    raiz = nullptr;
}

void EquipoArbol::crear(const char *filename) {
    ifstream input(filename, ios::in);
    class Player p;
    while (true) {
        p.read(input);
        if (input.eof()) break;
        insertar_recursivo(raiz,p);

    }
}

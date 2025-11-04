//
// Created by Erasmo on 29/10/25.
//

#include "NodoArbol.hpp"

NodoArbol::NodoArbol() {
    izq = nullptr;
    der = nullptr;
}

NodoArbol::NodoArbol(const NodoArbol &orig) {
    izq = orig.izq;
    der = orig.der;
}

NodoArbol::~NodoArbol() {
//    delete izq;
//    delete der;
}
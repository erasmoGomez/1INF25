//
// Created by erasmo on 6/10/26.
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
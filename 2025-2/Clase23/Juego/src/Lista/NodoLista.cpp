//
// Created by Erasmo on 29/10/25.
//

#include "NodoLista.hpp"

NodoLista::NodoLista() {
    sig = nullptr;
}

NodoLista::NodoLista(const NodoLista &orig) {
    dato = orig.dato;
    sig = nullptr;

}

NodoLista::~NodoLista() {
    //delete sig;
}
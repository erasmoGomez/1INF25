//
// Created by erasmo on 6/10/26.
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
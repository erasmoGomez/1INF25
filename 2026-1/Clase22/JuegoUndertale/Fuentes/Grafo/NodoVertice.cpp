//
// Created by erasmo on 6/10/26.
//

#include "NodoVertice.hpp"

NodoVertice::NodoVertice() {
    adyacentes = nullptr;
    cantidad_adyacentes = 0;
}

NodoVertice::~NodoVertice() {
    delete adyacentes;
    //For para el segundo nivel
}

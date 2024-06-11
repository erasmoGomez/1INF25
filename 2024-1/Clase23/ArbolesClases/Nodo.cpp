//
// Created by Erasmo on 8/06/24.
//

#include "Nodo.hpp"

Nodo::Nodo() {
    izq = nullptr;
    der = nullptr;
}

//Constructor copia
//*this  = orig;
// this -> El puntero al objeto con el q estan trabajando
// *ptr - valor - valor del puntero this = al objeto orig
Nodo::Nodo(const Nodo &orig) {
    cout<<"NODOOOO"<<endl;
    izq = nullptr;
    der = nullptr; //Seteo a nullptr
    *this = orig;
}

Nodo::~Nodo() {
}


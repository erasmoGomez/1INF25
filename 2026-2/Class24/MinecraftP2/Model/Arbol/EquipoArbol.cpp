//
// Created by erasmo on 11/4/26.
//

#include "EquipoArbol.hpp"

void EquipoArbol::insertar_recursivo(class NodoArbol *&_raiz, const Player& player) {
    //caso base
    if (_raiz == nullptr) {
        _raiz = new class NodoArbol();
        _raiz->dato = player;
        return;
    }
    //caso recursivo
    if (_raiz->dato > player) {
        insertar_recursivo(_raiz->izq, player);
    } else {
        insertar_recursivo(_raiz->der, player);
    }
}

void EquipoArbol::display_post_order_rec(class NodoArbol *_raiz, ofstream &output) {
    // HI HD R
    if(_raiz){
        display_post_order_rec(_raiz->izq, output);
        display_post_order_rec(_raiz->der, output);
        _raiz->dato.print(output); // Raiz
    }
}

void EquipoArbol::display_in_order_rec(class NodoArbol *_raiz, ofstream &output) {
    // HI R HD
    if(_raiz){
        display_in_order_rec(_raiz->izq, output);
        _raiz->dato.print(output); // Raiz
        display_in_order_rec(_raiz->der, output);
    }
}

EquipoArbol::EquipoArbol() {
    raiz = nullptr;
}

EquipoArbol::~EquipoArbol() {

}

void EquipoArbol::crear(const char *filename) {
    ifstream input(filename, ios::in);
    class Player p;
    class Player *ptr_player;
    char tipo;
    while (true) {
        p.read(input);
        if (input.eof()) break;
        ptr_player = reserva_memoria(tipo);
        insertar_recursivo(raiz, ptr_player);
    }
}

void EquipoArbol::in_order(const char *file_name) {
    ofstream output(file_name, ios::out);
    display_in_order_rec(raiz, output);
}

void EquipoArbol::post_order(const char *file_name) {
    ofstream output(file_name, ios::out);
    display_post_order_rec(raiz, output);
}

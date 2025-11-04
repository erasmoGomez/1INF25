//
// Created by Erasmo on 29/10/25.
//

#ifndef JUEGO_NODOARBOL_HPP
#define JUEGO_NODOARBOL_HPP

#include "../Heroe.hpp"
#include "EquipoArbol.hpp"

class NodoArbol {
public:
    NodoArbol();

    NodoArbol(const NodoArbol &orig);

    virtual ~NodoArbol();

    friend class EquipoArbol;
private:
    class Heroe dato;
    class NodoArbol *izq;
    class NodoArbol *der;
};


#endif //JUEGO_NODOARBOL_HPP

//
// Created by erasmo on 6/10/26.
//

#ifndef JUEGOUNDERTALE_NODOARBOL_HPP
#define JUEGOUNDERTALE_NODOARBOL_HPP

#include "../Personaje.hpp"

class NodoArbol {
public:
    NodoArbol();

    NodoArbol(const NodoArbol &orig);

    virtual ~NodoArbol();

    friend class EquipoArbol;
private:
    class Personaje dato;
    class NodoArbol *izq;
    class NodoArbol *der;
};

#endif //JUEGOUNDERTALE_NODOARBOL_HPP
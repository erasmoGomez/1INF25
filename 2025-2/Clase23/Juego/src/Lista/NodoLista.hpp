//
// Created by Erasmo on 29/10/25.
//

#ifndef JUEGO_NODOLISTA_HPP
#define JUEGO_NODOLISTA_HPP

#include "../Heroe.hpp"
#include "EquipoLista.hpp"

class NodoLista {
public:
    NodoLista();

    NodoLista(const NodoLista &orig);

    virtual ~NodoLista();

    friend class EquipoLista;

private:
    class Heroe dato;
    class NodoLista *sig;
};


#endif //JUEGO_NODOLISTA_HPP

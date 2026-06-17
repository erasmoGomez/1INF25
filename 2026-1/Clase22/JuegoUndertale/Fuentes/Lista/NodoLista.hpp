//
// Created by erasmo on 6/10/26.
//

#ifndef JUEGOUNDERTALE_NODOLISTA_HPP
#define JUEGOUNDERTALE_NODOLISTA_HPP
#include "../Personaje.hpp"
class NodoLista {
public:
    NodoLista();

    NodoLista(const NodoLista &orig);

    virtual ~NodoLista();

    friend class EquipoLista;

private:
    class Personaje dato;
    class NodoLista *sig;
};


#endif //JUEGOUNDERTALE_NODOLISTA_HPP
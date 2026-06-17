//
// Created by erasmo on 6/10/26.
//

#ifndef JUEGOUNDERTALE_NODOVERTICE_HPP
#define JUEGOUNDERTALE_NODOVERTICE_HPP

#include "../Personaje.hpp"

class NodoVertice {
public:
    NodoVertice();
    virtual ~NodoVertice();

    friend class EquipoGrafo;

private:
    Personaje dato;
    NodoVertice **adyacentes;
    int cantidad_adyacentes;

    // NodoVertice *adyacentes[30];
    // int cantidad_adyacentes;
    //
    // EquipoLista adyacentes;
    // int cantidad_adyacentes;
};

#endif //JUEGOUNDERTALE_NODOVERTICE_HPP
//
// Created by Erasmo on 29/10/25.
//

#ifndef JUEGO_EQUIPOLISTA_HPP
#define JUEGO_EQUIPOLISTA_HPP

#include "NodoLista.hpp"

class EquipoLista {
public:
    EquipoLista();

    EquipoLista(const EquipoLista &orig);

    virtual ~EquipoLista();

    void crear(const char *);

    void insertar(const class Heroe &);

    void imprimir(const char *);


private:
    class NodoLista *lista;

    void imprimir_recursivo(class NodoLista *ptr, ofstream &output);
};


#endif //JUEGO_EQUIPOLISTA_HPP

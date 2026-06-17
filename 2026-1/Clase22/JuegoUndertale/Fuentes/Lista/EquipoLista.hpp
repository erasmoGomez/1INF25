//
// Created by erasmo on 6/10/26.
//

#ifndef JUEGOUNDERTALE_EQUIPOLISTA_HPP
#define JUEGOUNDERTALE_EQUIPOLISTA_HPP
#include "NodoLista.hpp"

class EquipoLista {
public:
    EquipoLista();

    EquipoLista(const EquipoLista &orig);

    virtual ~EquipoLista();

    void crear(const char *);

    void insertar(const class Personaje &);

    void imprimir(const char *);


private:
    class NodoLista *lista;

    void imprimir_recursivo(class NodoLista *ptr, ofstream &output);
};


#endif //JUEGOUNDERTALE_EQUIPOLISTA_HPP
//
// Created by erasmo on 6/10/26.
//

#ifndef JUEGOUNDERTALE_EQUIPOGRAFO_HPP
#define JUEGOUNDERTALE_EQUIPOGRAFO_HPP
#include "NodoVertice.hpp"

class EquipoGrafo {
public:
    EquipoGrafo();
    virtual ~EquipoGrafo();

    void insertarVertice(const Personaje &p);
    void insertarArista(const Personaje &origen,
                        const Personaje &destino);

    void imprimir();

private:
    NodoVertice **vertices;
    int cantidad_vertices;
    NodoVertice *buscarVertice(const Personaje &p);
};


#endif //JUEGOUNDERTALE_EQUIPOGRAFO_HPP
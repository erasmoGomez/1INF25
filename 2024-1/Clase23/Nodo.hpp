//
// Created by Erasmo on 8/06/24.
//

#ifndef JUEGO_NODO_HPP
#define JUEGO_NODO_HPP
#include "Heroe.hpp"

//(Heroe, izq, der)
class Nodo {
public:
    Nodo();
    Nodo(const Nodo&);
    virtual ~Nodo();
    friend class Equipo; //Equipo -> Arbol
private:
    Heroe dato;
    Nodo *izq;
    Nodo *der;
};


#endif //JUEGO_NODO_HPP

//
// Created by erasmo on 11/4/26.
//

#ifndef MINECRAFTP2_EQUIPOARBOL_HPP
#define MINECRAFTP2_EQUIPOARBOL_HPP
#include "NodoArbol.hpp"

class EquipoArbol {
private:
    class NodoArbol* raiz;
    void insertar_recursivo(class NodoArbol *& raiz, const class Player player);
public:
    EquipoArbol();

    void crear(const char* filename);
};


#endif //MINECRAFTP2_EQUIPOARBOL_HPP
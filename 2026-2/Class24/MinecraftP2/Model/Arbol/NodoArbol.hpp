//
// Created by erasmo on 11/4/26.
//

#ifndef MINECRAFTP2_NODOARBOL_HPP
#define MINECRAFTP2_NODOARBOL_HPP

#include "../Player.hpp"

class NodoArbol {
private:
    class Player* dato;
    class NodoArbol *izq;
    class NodoArbol *der;

public:
    NodoArbol();
    // Vamos a realizar el
    // contrato con la clase EquipoArbol
    friend class EquipoArbol;
};


#endif //MINECRAFTP2_NODOARBOL_HPP

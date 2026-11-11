//
// Created by erasmo on 11/4/26.
//

#ifndef MINECRAFTP2_EQUIPOARBOL_HPP
#define MINECRAFTP2_EQUIPOARBOL_HPP
#include "NodoArbol.hpp"

class EquipoArbol {
private:
    class NodoArbol* raiz;
    void insertar_recursivo(class NodoArbol *& raiz, const Player& player);
    void display_post_order_rec(class NodoArbol * raiz, ofstream & output);
    void display_in_order_rec(class NodoArbol * raiz, ofstream & output);


public:
    EquipoArbol();

    virtual ~EquipoArbol();

    void crear(const char* filename);


    void in_order(const char * str);


    void post_order(const char * str);
};


#endif //MINECRAFTP2_EQUIPOARBOL_HPP
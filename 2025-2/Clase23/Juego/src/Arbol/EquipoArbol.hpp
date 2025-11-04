//
// Created by Erasmo on 29/10/25.
//

#ifndef JUEGO_EQUIPOARBOL_HPP
#define JUEGO_EQUIPOARBOL_HPP
#include "NodoArbol.hpp"

class EquipoArbol {
public:
    EquipoArbol();
    EquipoArbol(const EquipoArbol& orig);
    virtual ~EquipoArbol();
    void crear(const char*);
    void mostrar_en_orden(const char*);
    // void mostrar_post_orden(const char*);
private:
    class NodoArbol* arbol;
    void insertar_recursivo(class NodoArbol*&, const class Heroe h);
    void mostrar_en_orden_recursivo(class NodoArbol*&, ofstream& output);
};


#endif //JUEGO_EQUIPOARBOL_HPP

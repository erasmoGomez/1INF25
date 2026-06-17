//
// Created by erasmo on 6/10/26.
//

#ifndef JUEGOUNDERTALE_EQUIPOARBOL_HPP
#define JUEGOUNDERTALE_EQUIPOARBOL_HPP

#include "NodoArbol.hpp"

class EquipoArbol {
public:
    EquipoArbol();
    EquipoArbol(const EquipoArbol& orig);
    virtual ~EquipoArbol();
    void crear(const char*);
    void mostrar_en_orden(const char*);
    void mostrar_post_orden(const char*);
private:
    class NodoArbol* raiz;
    void insertar_recursivo(class NodoArbol*&, const class Personaje h);
    void mostrar_en_orden_recursivo(class NodoArbol*&, ofstream& output);
    void mostrar_post_orden_recursivo(class NodoArbol*&, ofstream& output);
    void mostrar_pre_orden_recursivo(class NodoArbol*&, ofstream& output);
};


#endif //JUEGOUNDERTALE_EQUIPOARBOL_HPP
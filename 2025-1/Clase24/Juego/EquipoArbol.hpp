/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   EquipoArbol.hpp
 * Author: hecto
 *
 * Created on June 4, 2025, 5:32 PM
 */

#ifndef EQUIPOARBOL_HPP
#define EQUIPOARBOL_HPP
#include "NodoArbol.hpp"
#include "utils.hpp"
class EquipoArbol {
public:
    EquipoArbol();
    EquipoArbol(const EquipoArbol& orig);
    virtual ~EquipoArbol();
    void crear(const char*);
    void mostrar_en_orden(const char*);
    void mostrar_post_orden(const char*);
private:
    class NodoArbol* equipo;
    void insertar_recursivo(class NodoArbol*&, const class Heroe);
    void mostrar_en_orden_recursivo(class NodoArbol*, ofstream&);
    void mostrar_post_orden_recursivo(class NodoArbol*, ofstream&);
};

#endif /* EQUIPOARBOL_HPP */


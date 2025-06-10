/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NodoArbol.hpp
 * Author: hecto
 *
 * Created on June 4, 2025, 5:30 PM
 */

#ifndef NODOARBOL_HPP
#define NODOARBOL_HPP
#include "utils.hpp"
#include "Heroe.hpp"
#include "EquipoArbol.hpp"
class NodoArbol {
public:
    NodoArbol();
    NodoArbol(const NodoArbol& orig);
    virtual ~NodoArbol();
    friend class EquipoArbol;
private:
    Heroe dato;
    NodoArbol* izq;
    NodoArbol* der;
};

#endif /* NODOARBOL_HPP */


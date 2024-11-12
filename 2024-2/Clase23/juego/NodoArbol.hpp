/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NodoArbol.hpp
 * Author: Erasmo G. Montoya
 *
 * Created on November 5, 2024, 5:29 PM
 */

#ifndef NODOARBOL_HPP
#define NODOARBOL_HPP
#include "Utils.hpp"
#include "Heroe.hpp"
#include "Equipo.hpp"
class NodoArbol {
public:
    NodoArbol();
    NodoArbol(const NodoArbol& orig);
    virtual ~NodoArbol();
    friend class Equipo;
private:
    Heroe dato;
    NodoArbol* izq;
    NodoArbol* der;
};

#endif /* NODOARBOL_HPP */


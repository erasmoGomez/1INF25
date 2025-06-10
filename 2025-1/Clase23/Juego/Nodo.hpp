/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Nodo.hpp
 * Author: hecto
 *
 * Created on June 4, 2025, 4:56 PM
 */

#ifndef NODO_HPP
#define NODO_HPP
#include "utils.hpp"
#include "Heroe.hpp"
#include "Equipo.hpp"
class Nodo {
public:
    Nodo();
    Nodo(const Nodo& orig);
    virtual ~Nodo();
    friend class Equipo;
private:
    Heroe dato;
    Nodo* sig;
};

#endif /* NODO_HPP */


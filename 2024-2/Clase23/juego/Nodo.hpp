/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Nodo.hpp
 * Author: Erasmo G. Montoya
 *
 * Created on November 4, 2024, 5:30 PM
 */

#ifndef NODO_HPP
#define NODO_HPP
#include "Utils.hpp"
#include "Heroe.hpp"
#include "Lista.hpp"
class Nodo {
public:
    Nodo();
    Nodo(const Nodo& orig);
    virtual ~Nodo();
    friend class Lista;
private:
    Heroe dato;
    Nodo* sig;
};

#endif /* NODO_HPP */


/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NodoLista.hpp
 * Author: Erasmo G. Montoya
 *
 * Created on June 11, 2024, 9:22 AM
 */

#ifndef NODOLISTA_HPP
#define NODOLISTA_HPP
#include "Heroe.hpp"
#include "Lista.hpp"

class NodoLista {
public:
    NodoLista();
    NodoLista(const NodoLista& orig);
    virtual ~NodoLista();
    friend class Lista;
private:
    Heroe dato;
    NodoLista* sig;
};

#endif /* NODOLISTA_HPP */


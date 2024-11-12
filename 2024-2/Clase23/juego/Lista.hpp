/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Lista.hpp
 * Author: Erasmo G. Montoya
 *
 * Created on November 4, 2024, 5:33 PM
 */

#ifndef LISTA_HPP
#define LISTA_HPP
#include "Nodo.hpp"
#include "Utils.hpp"
class Lista {
public:
    Lista();
    Lista(const Lista& orig);
    virtual ~Lista();
    void crear(const char*);
    void insertar(const class Heroe&);
    void imprimir(const char*);
private:
    void imprimir_recursivo(class Nodo*, ofstream&);
    class Nodo* lista;
};

#endif /* LISTA_HPP */


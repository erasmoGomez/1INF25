/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Lista.hpp
 * Author: Erasmo G. Montoya
 *
 * Created on June 11, 2024, 9:25 AM
 */

#ifndef LISTA_HPP
#define LISTA_HPP
#include "NodoLista.hpp"
class Lista {
public:
    Lista();
    Lista(const Lista& orig);
    virtual ~Lista();
    void crear();
    void insertar_elemento(const class Heroe&);
    void imprimir();
private:
    class NodoLista* lista;
    void imprime_recursivo(NodoLista*, ofstream&);
};

#endif /* LISTA_HPP */


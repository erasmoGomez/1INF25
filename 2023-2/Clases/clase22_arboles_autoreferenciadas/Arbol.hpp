/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Arbol.hpp
 * Author: ASUS
 *
 * Created on November 7, 2023, 12:59 AM
 */

#ifndef ARBOL_HPP
#define ARBOL_HPP
#include "utils.hpp"
#include "Hero.hpp"
#include "Node.hpp"
class Arbol {
public:
    Arbol();
    Arbol(const Arbol& orig);
    virtual ~Arbol();
    void crear(const char*);
    void insertar(const class Hero&);
    void en_orden();
    void elimina();
    class Hero buscar(const char*);
private:
    class Node *arbol;
    void insertar_recursivo(class Node* &arbol,const class Hero&);
    void en_orden_recursivo(class Node*arbol);
    void eliminar_recursivo(class Node*arbol);
    class Hero buscar_recursivo(class Node*arbol,const char *);
};

#endif /* ARBOL_HPP */


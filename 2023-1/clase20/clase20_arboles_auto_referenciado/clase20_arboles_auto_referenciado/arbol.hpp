/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   arbol.hpp
 * Author: erasmog
 *
 * Created on June 27, 2023, 6:30 AM
 */

#ifndef ARBOL_HPP
#define ARBOL_HPP

#include "persona.hpp"
#include "nodo.hpp"

class Arbol{
private:
    class Nodo *arbol;
    //Definir metodos privados
    void eliminar(class Nodo *);
    void insertar_restrictivo(class Nodo *&, const class Persona&);
    void recorrer_en_pre_orden_restrictivo(class Nodo *arbol);
    void recorrer_en_orden_restrictivo(class Nodo *arbol);
    class Persona buscar_restrictivo(class Nodo *arbol, int);
public:
    Arbol();
    virtual ~Arbol();
    void crear(const char*);
    void insertar(const class Persona&);
    void recorrer_en_pre_orden();
    void recorrer_en_orden();
    class Persona buscar(int);
};

#endif /* ARBOL_HPP */


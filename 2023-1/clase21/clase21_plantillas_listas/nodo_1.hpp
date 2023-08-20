/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   nodo.hpp
 * Author: erasmog
 *
 * Created on June 27, 2023, 6:30 AM
 */

#ifndef NODO_HPP
#define NODO_HPP
#include "persona.hpp"
#include "arbol.hpp"

class Nodo{
private:
    class Persona dato;
    class Nodo *izq;
    class Nodo *der;
public:
    Nodo();
    //Declar clases amigas!
    friend class Arbol;
};



#endif /* NODO_HPP */


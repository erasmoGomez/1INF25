/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Equipo.hpp
 * Author: hecto
 *
 * Created on June 4, 2025, 4:53 PM
 */

#ifndef EQUIPO_HPP
#define EQUIPO_HPP
#include "Nodo.hpp"
#include "utils.hpp"
class Equipo {
public:
    Equipo();
    Equipo(const Equipo& orig);
    virtual ~Equipo();
    void crear(const char*);
    void insertar(const class Heroe&);
    void imprimir(const char*);
private:
    void imprimir_recursivo(class Nodo*ptr, ofstream&);
    class Nodo* lista;

};

#endif /* EQUIPO_HPP */


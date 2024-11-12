/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Equipo.hpp
 * Author: Erasmo G. Montoya
 *
 * Created on November 5, 2024, 5:24 PM
 */

#ifndef EQUIPO_HPP
#define EQUIPO_HPP
#include "NodoArbol.hpp"
#include "Utils.hpp"
class Equipo {
public:
    Equipo();
    Equipo(const Equipo& orig);
    virtual ~Equipo();
    void crear(const char*);
    void mostrar_en_orden(const char*);
    void mostrar_post_orden(const char*);
private:
    void mostrar_en_orden_recursivo(class NodoArbol*, ofstream &);
    void mostrar_post_orden_recursivo(class NodoArbol*, ofstream &);
    void insertar_recursivo(class NodoArbol*&, const class Heroe&);
    class NodoArbol* equipo;
};

#endif /* EQUIPO_HPP */


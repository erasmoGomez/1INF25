/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaGenerica.hpp
 * Author: Erasmo G. Montoya
 *
 * Created on April 28, 2026, 5:01 PM
 */

#ifndef LISTAGENERICA_HPP
#define LISTAGENERICA_HPP
#include "Helpers.hpp"

void crear_lista(const char *,
                 void *&,
                 void *(*)(ifstream &),
                 int (*)(const void *, const void *));

void insertar(void *, void *&, int (*)(const void *, const void *));

void imprimir_lista(const char *, void *lista, void (*imprime)(void *, ofstream &));
#endif /* LISTAGENERICA_HPP */

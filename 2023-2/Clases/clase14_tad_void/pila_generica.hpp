/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   pila_generica.hpp
 * Author: ASUS
 *
 * Created on September 25, 2023, 4:47 AM
 */

#ifndef PILA_GENERICA_HPP
#define PILA_GENERICA_HPP

#include "auxiliares.hpp"

void crear_pila(const char *, void *&, void* (*)(ifstream &));
void apilar(void *&, void *);
void desapilar(void *, void (*)(void*));

#endif /* PILA_GENERICA_HPP */


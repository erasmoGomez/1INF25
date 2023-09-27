/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   lista_generica.hpp
 * Author: ASUS
 *
 * Created on September 25, 2023, 3:59 AM
 */

#ifndef LISTA_GENERICA_HPP
#define LISTA_GENERICA_HPP
#include "auxiliares.hpp"

void crear_lista(const char *, void *&, void* (*)(ifstream &), int (*)(const void*, const void*));
void insertar_lista(void *&, void *, int (*)(const void*, const void*));
void imprimir_lista(const char *, void *, void (*)(void*, ofstream &));
void eliminar_lista(void *, void (*)(void*));

#endif /* LISTA_GENERICA_HPP */


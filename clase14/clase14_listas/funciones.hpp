/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   funciones.hpp
 * Author: erasmog
 *
 * Created on May 30, 2023, 8:07 AM
 */

#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>
using namespace std;

void insertar_lista(void *&, void *);
void insertar_lista_ordenado(void *&, void *, int(*)(const void*, const void*));
void * leer_entero(ifstream &);
void * leer_registro(ifstream &);
int cmp_registro_multi_criterio(const void* , const void* );
void imprimir_lista(void *, void (*)(void*));
void imprimir_registro(void* );
void eliminar_registro(void* );
void crear_lista(ifstream &, void *&, void*(*)(ifstream &));
void crear_lista(ifstream &, void *&, void*(*)(ifstream &), int(*)(const void*, const void*));
void eliminar_lista(void *, void(*)(void*));
void imprimir_entero(void* );


#endif /* FUNCIONES_HPP */


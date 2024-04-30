/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   functions.hpp
 * Author: ASUS
 *
 * Created on April 25, 2024, 8:14 AM
 */

#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP
#include "utils.hpp"
using namespace std;
void crear_lista(const char *,void*&, void*(*lee)(ifstream&), int(*cmp)(const void*, const void*));
void* leer_registro(ifstream&);
void* leer_enteros(ifstream&);
int cmp_registro_str(const void*, const void*);
int cmp_enteros(const void*, const void*);
void insertar(void *, void*&, int(*)(const void*, const void*));
void imprime_lista(const char*, void *, void (*)(ofstream&, void*));
void imprime_registro(ofstream&, void*);
void eliminar_lista(void*, void(*)(void*));
void elimina_registro(void*l);
#endif /* FUNCTIONS_HPP */


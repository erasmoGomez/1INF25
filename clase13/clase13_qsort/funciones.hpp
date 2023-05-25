/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   funciones.hpp
 * Author: erasmog
 *
 * Created on May 23, 2023, 8:47 AM
 */

#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>
using namespace std;
int cmp(const void*, const void*);
int cmp_str(const void*, const void*);
int cmp_nombres_void(const void*, const void*);
int cmp_sueldos_void(const void*, const void*);
int cmp_codigo_void(const void*, const void*);
int cmp_multicriterio_void(const void*, const void*);
void leer_datos_str(char **& personas, int &n);
void imprimir_personas(char** personas, int n);
void leer_datos_void(void *&,int &);
void imprimir_datos_void(void *, int );


#endif /* FUNCIONES_HPP */


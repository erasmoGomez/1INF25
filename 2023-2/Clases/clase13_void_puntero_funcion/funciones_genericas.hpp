/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   funciones_genericas.hpp
 * Author: ASUS
 *
 * Created on September 20, 2023, 7:16 AM
 */

#ifndef FUNCIONES_GENERICAS_HPP
#define FUNCIONES_GENERICAS_HPP
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
enum RegistroPersonal {CODIGO, NOMBRE, SUELDO};
void leer_datos_personal(void*&, int &);
int funcion_comparacion_codigos(const void *, const void *);
int funcion_comparacion_nombres(const void *, const void *);
int funcion_comparacion_propia_codigos(const void *, const void *);
int funcion_comparacion_propia_sueldos(const void *, const void *);
void imprimir_datos(void*, int );
void ordenar_personal(void *, int izq,int der, int (*)(const void*, const void*));
#endif /* FUNCIONES_GENERICAS_HPP */


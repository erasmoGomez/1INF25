/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   funciones_genericas.hpp
 * Author: hecto
 *
 * Created on April 16, 2025, 4:24 PM
 */

#ifndef FUNCIONES_GENERICAS_HPP
#define FUNCIONES_GENERICAS_HPP
#include "utils.hpp"

void cargar_alumnos(void*&, const char*);
void cargar_notas(void*, const char*);
void calcular_promedio(void*);
void probar_carga(void*, const char*);
void ordenar(void*);
int obtener_cantidad(void*);
int compara_cadenas(const void*, const void*);
int compara_enteros(const void*, const void*);
int comparar_orden_generico(const void*, const void*);
void quick_sort_generico(void*, int, int, int(*)(const void*, const void*));
#endif /* FUNCIONES_GENERICAS_HPP */

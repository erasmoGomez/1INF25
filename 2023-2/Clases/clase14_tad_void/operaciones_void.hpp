/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   operaciones_void.hpp
 * Author: ASUS
 *
 * Created on September 25, 2023, 4:22 AM
 */

#ifndef OPERACIONES_VOID_HPP
#define OPERACIONES_VOID_HPP
#include "auxiliares.hpp"

void *leer_registro(ifstream &);
int cmp_registros_nombre(const void *, const void*);
void imprimir_registro(void*, ofstream&);
void eliminar_registro(void*);

#endif /* OPERACIONES_VOID_HPP */


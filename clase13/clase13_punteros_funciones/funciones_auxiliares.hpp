/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   funciones_auxiliares.hpp
 * Author: erasmog
 *
 * Created on May 23, 2023, 7:49 AM
 */

#ifndef FUNCIONES_AUXILIARES_HPP
#define FUNCIONES_AUXILIARES_HPP

int suma(int, int);
int resta(int, int);
int mult(int, int);

void * hace_algo_2(void* a);
void * hace_algo_1(void* a);

int operacion(int, int, int (*ptr_funcion)(int, int));


#endif /* FUNCIONES_AUXILIARES_HPP */


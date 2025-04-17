/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   funciones.hpp
 * Author: hecto
 *
 * Created on April 8, 2025, 6:29 PM
 */

#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP
#include "utils.hpp"
void lectura_productos(char***&, int*&, double*&, const char*);
char* leer_cadena(ifstream &, int , char );
char** lee_productos(ifstream&);
void prueba_lectura_productos(char***, int*, double*, const char*);
void actualizar_productos(char***&, int*&, double*&,
                         char***, int*, double*,
                         int );

void lectura_pedidos(int*&, char***&, int***&, const char*);
#endif /* FUNCIONES_HPP */

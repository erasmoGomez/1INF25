/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   funciones.hpp
 * Author: Erasmo G. Montoya
 *
 * Created on September 10, 2024, 6:18 PM
 */

#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP

#include "utils.hpp"
void lectura_productos(char***&, int*&, double*&, const char*);
void prueba_lectura_productos(char***, int*, double*, const char*);
void actualizar_productos(char***&, int*&, double*&, char***, int*, double*, int);
char** lee_productos(ifstream &);
#endif /* FUNCIONES_HPP */


/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   funciones.hpp
 * Author: Erasmo G. Montoya
 *
 * Created on September 2, 2024, 6:10 PM
 */

#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP
#include "Utils.hpp"
void cargar_alumnos(int*&, char**&,const char*);
void cargar_cursos(int*,char***&,const char*);
char* leer_cadena(ifstream &, char);
void imprimir_alumnos(int*, char**, const char*);
#endif /* FUNCIONES_HPP */


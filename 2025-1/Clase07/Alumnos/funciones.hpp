/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   funciones.hpp
 * Author: hecto
 *
 * Created on April 2, 2025, 4:35 PM
 */

#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP
#include "utils.hpp"
void cargar_alumnos(int*&, char**&, const char*);
void imprimir_alumnos(int*, char**, const char*);
void imprimir_alumnos(int*, char**, char***, const char*);
void cargar_cursos(int*, char***&, const char*);
void cargar_alumnos_incrementos(int*&, char**&, const char*);
void reservar_memoria_incrementos(int*&, char**&, int &, int &);
void reservar_memoria_incrementos(char**&, int&, int&);
void cargar_cursos_incrementos(int*, char***&, const char*);
void colocar_curso(ifstream &, char**&, int &, int &);
#endif /* FUNCIONES_HPP */

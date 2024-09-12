/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Funciones.hpp
 * Author: Erasmo G. Montoya
 *
 * Created on September 9, 2024, 6:08 PM
 */

#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP

#include "Utils.hpp"
void cargar_alumnos(int*&, char**&,const char*);
void cargar_cursos(int*,char***&,const char*);
char* leer_cadena(ifstream &, char);
void imprimir_alumnos(int*, char**, const char*);
int buscar_alumno(int, int*, int);
void colocar_curso(ifstream &, char**&, int &, int&);
void recortar(char** &, int);
void reservar_memoria_incrementos(int*&, char**&,int &, int &);
void reservar_memoria_incrementos(char**&, int&, int&);
void imprimir_alumnos(int*, char**, char***, const char*);
void cargar_cursos(int*,char*** &,const char*);
int buscar_alumno(int, int*);
void reporte_cursos(ofstream &,char**);
#endif /* FUNCIONES_HPP */


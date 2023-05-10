/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   funciones.hpp
 * Author: erasmog
 *
 * Created on May 9, 2023, 3:01 AM
 */

#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#define INCREMENTO 5

using namespace std;
void cargar_alumnos(void *&);
void reporte_alumnos(void *); //En el reporte no le pongo & por q no me interesa cambiar valores
void *leer_registro(ifstream &);
void incrementar_espacios(void **&, int &, int &);
char *leer_cadena(ifstream &);
void imprimir_alumno(void *);

#endif /* FUNCIONES_HPP */


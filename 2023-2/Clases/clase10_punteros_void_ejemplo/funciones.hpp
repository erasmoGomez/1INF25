/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   funciones.hpp
 * Author: ASUS
 *
 * Created on September 13, 2023, 7:50 AM
 */

#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
char *leer_cadena(ifstream &, char = '\n');
void cargar_alumnos(void *&);
void probar_alumnos(void *);
void cargar_notas(void *&);
void calcular_promedios(void *&);
#endif /* FUNCIONES_HPP */


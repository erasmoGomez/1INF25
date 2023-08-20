/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   funciones.hpp
 * Author: erasmog
 *
 * Created on May 9, 2023, 12:44 AM
 */

#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

#define INCREMENTO 5

void cargarAlumnos(int *&codigo,char **&nombre,char ***&cursos);
//void reporteDeAlumnos(int *codigo,char **nombre,char ***cursos);
char *leeCadena(ifstream &arch);
void aumentarEspacios(int *&,char **&,char ***&,int &,int &);
char **leeCursos(ifstream &arch);
char *leerCad(ifstream &arch);
void aumentarEspacios(char **&curso,int &nd,int &cap);
//void imprimeCursos(char **cursos);

#endif /* FUNCIONES_HPP */


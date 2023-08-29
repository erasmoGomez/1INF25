/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   functions.hpp
 * Author: ASUS
 *
 * Created on August 29, 2023, 9:10 AM
 */

#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP
#include <fstream>
using namespace std;
char ** leer_cursos(ifstream &);
char * leer_cadena(ifstream &);
void cargar_alumnos(int *&, char **&, char ***&, const char*);
void reporte_cursos(char **, ofstream &);
void reporte_alumnos(int *, char **, char ***, const char*);
#endif /* FUNCTIONS_HPP */


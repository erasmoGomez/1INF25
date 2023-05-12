/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   MetodoPorIncrementos.h
 * Author: jfatamav
 *
 * Created on 12 de mayo de 2023, 09:34
 */

#ifndef METODOPORINCREMENTOS_H
#define METODOPORINCREMENTOS_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#define INCREMENTO 5
#define PRECIOESCALA1 282.3
#define PRECIOESCALA2 362
#define PRECIOESCALA3 454.2
#define PRECIOESCALA4 556.7
#define PRECIOESCALA5 666.9

using namespace std;

void cargarDatos(const char*, char***&, int*&, char****&, double**&);
void pruebaCursos(const char*, char***, int*, char****, double**);
void reporteDeAlumnosPorCurso(const char*, char***, int*, char****, double**);

void incrementarEspacios(char***&, int*&, char****&, double**&, int&, int&);

void procesarAlumnosEnCurso(ifstream&, char***&, int, double*&);
void incrementarPunteroCaracterTriple(char***&, int&, int&);
void asignarCadena(char*&, char*);
void imprimirDetalleAlumnosCurso(ofstream&, char ***, int, double&);
void imprimirAlumnoYAcumularTotalCurso(ofstream&, int, char**, int, double&);
double obtenerPrecioPorEscala(int);
void imprimirLinea(ofstream&, char, int);

#endif /* METODOPORINCREMENTOS_H */


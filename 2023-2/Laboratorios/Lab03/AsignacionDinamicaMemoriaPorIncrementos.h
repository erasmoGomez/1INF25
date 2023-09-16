/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   AsignacionDinamicaMemoriaPorIncrementos.h
 * Author: Jorge Fatama
 *
 * Created on 16 de setiembre de 2023, 10:34
 */

#ifndef ASIGNACIONDINAMICAMEMORIAPORINCREMENTOS_H
#define ASIGNACIONDINAMICAMEMORIAPORINCREMENTOS_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#define INCREMENTO 5
using namespace std;

void lecturaDeProductos (const char*, char***&, int*&, double*&);
void pruebaDeLecturaDeProductos (const char*, char ***, int*, double *);
void lecturaDePedidos (const char*, int*&, char***&, int***&);
void pruebaDeLecturaDePedidos (const char*, int*, char***, int***);
void reporteDeEnvioDePedidos (const char*, char***&, int*&, double*&, int*&,
        char***&, int***&);

void incrementarMemoriaProductos(char***&, int*&, double*&, int&, int&);
void insertarEnMemoriaProductos(char***&, int*&, double*&, const char*, const char*, int,
        double, int);
void almacenarCadenaDinamica(const char*, char*&);
void imprimirLinea(ofstream&, char, int);

#endif /* ASIGNACIONDINAMICAMEMORIAPORINCREMENTOS_H */


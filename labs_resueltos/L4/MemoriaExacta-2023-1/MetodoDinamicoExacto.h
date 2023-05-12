/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MetodoDinamicoExacto.h
 * Author: alulab14
 *
 * Created on 5 de mayo de 2023, 08:14 AM
 */

#ifndef METODODINAMICOEXACTO_H
#define METODODINAMICOEXACTO_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#define IND_PRESENCIAL 0
#define IND_SEMI 1
#define IND_VIRTUAL 2
using namespace std;

void lecturaAlumnos(const char *, int*&, char**&, char*&, int*&, int*&);
void pruebaLecturaAlumnos(const char *, int*, char**, char*, int*, int*);
void lecturaCursos(const char *, int*, int*, char**&, double*&, int**&);
void pruebaDeLecturaCursos(const char *, char**, double*, int**);
void reporteDeRecaudacionPorModalidad(const char*, int*, char*, int*, char**,
        char**, double*, int**);

void procesarArchivoAlumnos(ifstream&, int*, int*, int*, char*&, char**, int&);
void procesarArchivoCursos(ifstream&, char**, double*, int**, int*, int*, int&);
void memoriaExactaEntera(int*&, int*, int);
void memoriaExactaPuntoFlotante(double*&, double*, int);
void memoriaExactaCadena(char*&, char*, int);
void memoriaExactaArregloCadena(char**&, char**, int);
void memoriaExactaArregloAlumnos(int**&, int**, int);
void procesarDemasDatosDeAlumno(ifstream&, char*&, int&, char&, int&);
void procesarCurso(char*, double, int, int, int&, char**, double*, int**);
void imprimirCabeceraGeneral(ofstream&);
void imprimirCabeceraCurso(ofstream&, int, char*, int);
void imprimirYActualizarDetalleAlumno(ofstream&, int, char**, char*, int*, 
        double*, int, double, double*);
void imprimirResumenCurso(ofstream&, double*, double*);
void imprimirResumenGeneral(ofstream&, double*);

int buscarIndiceAlumno(int, int*);
int cursoEstaRegistrado(char*, char **, int);
void leerEscalas(double*&);
void imprimirNombre(ofstream&, char*, bool);
int imprimirCapitalizacion(ofstream&, char*, bool);
void imprimirLinea(ofstream&, char, double, bool);


#endif /* METODODINAMICOEXACTO_H */


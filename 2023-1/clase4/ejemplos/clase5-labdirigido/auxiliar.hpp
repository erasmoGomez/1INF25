/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   auxiliar.hpp
 * Author: erasmog
 *
 * Created on April 4, 2023, 7:50 AM
 */

#ifndef AUXILIAR_HPP
#define AUXILIAR_HPP
#include <iostream>
#include <iomanip>
#include <fstream>
#define ANCHO_REPORTE 100
using namespace std;

void imprimir_linea_archivo(char, int, ofstream &);
void imprimir_linea(char, int);
void imprimir_encabezado_inicial(ofstream &);
void imprimir_datos_cursos(int , char* , double , int , int , int , int , int , int , int , ofstream & );
void imprimir_datos_alumnos(ifstream &, ofstream &);
void imprimir_alumno(int , int , char* , ofstream &);
void imprimir_resumen_final(int, ofstream &);
void imprimir_estadisticas_alumno(int, int, double, double, double, double, double, int, ofstream &);
void leer_alumno(int, int&, ifstream &, ofstream &);
void leer_curso(int, int &, int &, int &, double &, double &,double &, double &, double &, int &, ifstream & archivo_entrada, ofstream &archivo_salida);

#endif /* AUXILIAR_HPP */


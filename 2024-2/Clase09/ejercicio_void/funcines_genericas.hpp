/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   funcines_genericas.hpp
 * Author: Erasmo G. Montoya
 *
 * Created on September 17, 2024, 3:33 PM
 */

#ifndef FUNCINES_GENERICAS_HPP
#define FUNCINES_GENERICAS_HPP
#include "utils.hpp"
void cargar_alumnos(void *&alumnos, const char*nombArch);
void probar_carga(void *alumnos, const char*);
void *leerRegistro(ifstream &arch);
char *leer_cadena(ifstream &arch, char = '\n');
void incrementar_memoria(void **&alumnos, int &nd, int &cap);
void imprimir_alumno(void *al, ofstream&);
void cargarNotas(void *al, const char*nombArch);
int buscar(int cod, void **alumnos);
bool sonIguales(int cod, void*al);
void colocarCurso(ifstream &arch, void *al, int &nd, int &cap);
void incrementarEspacios(void *&al, int &nd, int &cap);
void *leeRCurso(ifstream &arch);
void agregarCurso(void*cur, void *alNota, int nd);
void imprimirCursos(void *cur);
void imprimirCurso(void *cur);
void calcular_promedios(void *alumnos);
void promedioDelAlumno(void *al);
void *promedio(void *al);
int obtenerNota(void *cur);
void imprimirPromedio(void *pro);
void ordenar(void *al);
void quick_sort(void**alumnos, int izq, int der);
void qsort2(void **notas, int izq, int der);
bool comparar_orden(void*al1, void*al2);



#endif /* FUNCINES_GENERICAS_HPP */


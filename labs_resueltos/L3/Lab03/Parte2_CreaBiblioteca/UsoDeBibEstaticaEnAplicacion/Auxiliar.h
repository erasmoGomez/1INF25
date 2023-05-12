/* 
 * File:   Auxiliar.h
 * Author: Jorge Fatama Vera <jorge.fatama@pucp.edu.pe>
 *
 * Created on 28 de abril de 2023, 10:20
 */

#ifndef AUXILIAR_H
#define AUXILIAR_H

#include "AperturaDeArchivos.h"
#include "AuxBiblio.h"
#include "Estructuras.h"
using namespace std;

void leerCursos(ifstream&, struct StCurso*);
void leerAlumnos(ifstream&, struct StAlumno*);
void leerMatriculas(ifstream&, struct StCurso*, struct StAlumno*);
void calcularCostos(struct StCurso*, struct StAlumno*);
void imprimirReporte(ofstream&, struct StCurso*, struct StAlumno*);

double* leerEscalas();
void procesarPagosEnCursos(struct StCurso*, struct StAlumno*, double*);
void procesarPagosEnAlumnos(struct StAlumno*, struct StCurso*, double*);
void obtenerDatosAlumno(struct StAlumno*, int, int, int&, int&);
double obtenerCreditosCurso(struct StCurso*, const char*);
int calcularPorcentaje(const struct StAlumno);

#endif /* AUXILIAR_H */


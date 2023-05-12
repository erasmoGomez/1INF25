/* 
 * File:   main.cpp
 * Author: Jorge Fatama Vera <jorge.fatama@pucp.edu.pe>
 *
 * Created on 28 de abril de 2023, 08:41 AM
 */

#ifndef AUXBIBLIO_H
#define AUXBIBLIO_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include "Estructuras.h"
using namespace std;

// Pruebas
void probarCurso(ifstream&, ofstream&, struct StCurso&, struct StCurso);
void probarAlumno(ifstream&, ofstream&, struct StAlumno&, struct StAlumno);
void probarMatricula(ifstream&, ofstream&, struct StCurso&, struct StAlumno&,
        struct StCurso, struct StAlumno);

// Lectura
bool operator>>(ifstream&, struct StCurso&);
bool operator>>(ifstream&, struct StAlumno&);
bool operator>>(ifstream&, struct StRegistroDeMatricula&);
// Agregación
void operator+=(struct StCurso*, const struct StCurso);
void operator+=(struct StAlumno*, const struct StAlumno);
void operator*=(struct StCurso*, const struct StRegistroDeMatricula);
void operator*=(struct StAlumno*, const struct StRegistroDeMatricula);
// Impresión
ofstream& operator<<(ofstream&, const struct StCurso&);
ofstream& operator<<(ofstream&, const struct StAlumno&);

const char* devolverCadenaModalidad(char);

#endif /* AUXBIBLIO_H */


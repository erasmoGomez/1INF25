/* 
 * File:   PruebaBiblio.h
 * Author: Jorge Fatama Vera <jorge.fatama@pucp.edu.pe>
 *
 * Created on 29 de abril de 2023, 03:44
 */

#ifndef PRUEBABIBLIO_H
#define PRUEBABIBLIO_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include "AuxBiblio.h"
using namespace std;

// Pruebas
void probarCurso(ifstream&, ofstream&, struct StCurso*, struct StCurso);
void probarAlumno(ifstream&, ofstream&, struct StAlumno*, struct StAlumno);
void probarMatricula(ifstream&, ofstream&, struct StCurso*, struct StAlumno*,
        struct StCurso, struct StAlumno);

#endif /* PRUEBABIBLIO_H */


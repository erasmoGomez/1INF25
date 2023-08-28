/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Sobrecargas.hpp
 * Author: ASUS
 *
 * Created on August 23, 2023, 6:56 AM
 */

#ifndef SOBRECARGAS_HPP
#define SOBRECARGAS_HPP
#include <fstream>
using namespace std;

void operator *= (struct Persona &, double);
struct Persona operator + (const struct Persona &, const struct Persona &);
ostream & operator << (ostream &, const struct Persona &);
//Lectura
bool operator >> (ifstream &, struct StCurso &);
bool operator >> (ifstream &, struct StAlumno &);
bool operator >> (ifstream &, struct StRegistroDeMatricula &);

//Agregacion
void operator += (struct StCurso *, const struct StCurso &);
void operator += (struct StAlumno *, const struct StAlumno &);
void operator *= (struct StCurso *, const struct StRegistroDeMatricula &);
void operator *= (struct StAlumno *, const struct StRegistroDeMatricula &);

//Impresion
void operator << (ofstream &, const struct StCurso &);
void operator << (ofstream &, const struct StAlumno &);
#endif /* SOBRECARGAS_HPP */


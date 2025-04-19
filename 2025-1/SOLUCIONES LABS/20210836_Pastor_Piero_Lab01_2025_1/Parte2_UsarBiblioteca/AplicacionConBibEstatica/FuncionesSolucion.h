/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   FuncionesSolucion.h
 * Author: piero
 *
 * Created on 15 de abril de 2025, 07:58 AM
 */

#ifndef FUNCIONESSOLUCION_H
#define FUNCIONESSOLUCION_H

#include "Utils.h"
#include "CadenaDeCaracteres.h"
#include "Sobrecargas.h"

#define MAX_TAM 36

void LeerDatos(const char *, int *&, CadenaDeCaracteres *&, CadenaDeCaracteres *&);
void OrdenarDatos(int *, CadenaDeCaracteres *, CadenaDeCaracteres *);
void QSort(int *, CadenaDeCaracteres *, CadenaDeCaracteres *, int, int);
void SwitchDatos(int *, CadenaDeCaracteres *, CadenaDeCaracteres *, int, int);
void ImprimirReporte(const char *, int *, CadenaDeCaracteres *, CadenaDeCaracteres *);
void ImprimirEncabezado(ofstream &);

#endif /* FUNCIONESSOLUCION_H */

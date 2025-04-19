/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Sobrecargas.h
 * Author: piero
 *
 * Created on 14 de abril de 2025, 11:21 PM
 */

#ifndef SOBRECARGAS_H
#define SOBRECARGAS_H

#include "Utils.h"
#include "Funciones.h"
#include "CadenaDeCaracteres.h"

void operator !(CadenaDeCaracteres &cad);

void operator <=(CadenaDeCaracteres &cad, char* cadena);
void operator <=(CadenaDeCaracteres &cad, int n);
void operator <=(CadenaDeCaracteres &cad1, CadenaDeCaracteres &cad2);

bool operator +=(CadenaDeCaracteres &cad, char* cadena);
bool operator +=(CadenaDeCaracteres &cad1, CadenaDeCaracteres &cad2);

bool operator ==(CadenaDeCaracteres &cad, char* cadena);
bool operator <(CadenaDeCaracteres &cad, char* cadena);
bool operator >(CadenaDeCaracteres &cad, char* cadena);

bool operator ==(CadenaDeCaracteres &cad1, CadenaDeCaracteres &cad2);
bool operator <(CadenaDeCaracteres &cad1, CadenaDeCaracteres &cad2);
bool operator >(CadenaDeCaracteres &cad1, CadenaDeCaracteres &cad2);

int operator >> (ifstream &arch, CadenaDeCaracteres &cad);

void operator &&(CadenaDeCaracteres &cad1, CadenaDeCaracteres &cad2);

ofstream& operator << (ofstream &arch, CadenaDeCaracteres &cad);

#endif /* SOBRECARGAS_H */

//
// Created by erasm on 1/04/2026.
//

#ifndef BIBLIOTECA_2025_1_FUENTES_SOBRECARGAS_HPP
#define BIBLIOTECA_2025_1_FUENTES_SOBRECARGAS_HPP
#include "Utils.hpp"
#include "Estructura.hpp"

void operator ! (struct CadenaDeCaracteres &cadena); // !cadena
void operator <= (struct CadenaDeCaracteres &cadena,const char* cad); //cadena <= cad o cadena <= "erasmo"
void operator <= (struct CadenaDeCaracteres &cadena, int espacio);
void operator <= (struct CadenaDeCaracteres &cad1,
        struct CadenaDeCaracteres &cad2);
bool operator += (struct CadenaDeCaracteres &cadena,const char* cad);
bool operator += (struct CadenaDeCaracteres &cad1,
        struct CadenaDeCaracteres &cad2);
int compare (struct CadenaDeCaracteres &cadena,const char* cad);
bool operator == (struct CadenaDeCaracteres &cadena,const char* cad);
bool operator > (struct CadenaDeCaracteres &cadena,const char* cad);
bool operator < (struct CadenaDeCaracteres &cadena,const char* cad);
int compare (struct CadenaDeCaracteres &cad1,
        struct CadenaDeCaracteres &cad2);
bool operator == (struct CadenaDeCaracteres &cad1,
        struct CadenaDeCaracteres &cad2);
bool operator > (struct CadenaDeCaracteres &cad1,
        struct CadenaDeCaracteres &cad2);
bool operator < (struct CadenaDeCaracteres &cad1,
        struct CadenaDeCaracteres &cad2);
int operator >> (ifstream &arch,struct CadenaDeCaracteres &cadena);
void operator && (struct CadenaDeCaracteres &cad1,
        struct CadenaDeCaracteres &cad2);
ofstream& operator << (ofstream &arch,struct CadenaDeCaracteres cadena);

#endif //BIBLIOTECA_2025_1_FUENTES_SOBRECARGAS_HPP
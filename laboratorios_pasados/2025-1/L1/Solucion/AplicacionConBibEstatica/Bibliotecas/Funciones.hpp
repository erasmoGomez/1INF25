//
// Created by erasm on 1/04/2026.
//

#ifndef APLICACIONCONBIBESTATICA_FUNCIONES_HPP
#define APLICACIONCONBIBESTATICA_FUNCIONES_HPP
#include "Utils.hpp"
#include "Estructura.hpp"
#include "Sobrecargas.hpp"

void leerDatos(int * dni,struct CadenaDeCaracteres* conductor,
        struct CadenaDeCaracteres* placa,int &numDat,const char* nomb);
void imprimirRep(int * dni,struct CadenaDeCaracteres* conductor,
        struct CadenaDeCaracteres* placa,int numDat,const char* nomb);
void imprimirLinea(ofstream &archR,int len,char c);
void ordenarDatos(int * dni,struct CadenaDeCaracteres* conductor,
        struct CadenaDeCaracteres* placa,int &numDat);
void mayusMinus(char *cad);

#endif //APLICACIONCONBIBESTATICA_FUNCIONES_HPP
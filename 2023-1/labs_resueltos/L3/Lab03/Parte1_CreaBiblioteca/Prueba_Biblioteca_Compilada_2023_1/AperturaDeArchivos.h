/* 
 * Proyecto: AperturaDeArchivos
 * Archivo:  AperturaDeArchivos.h
 * Autor:    J. Miguel Guanira E.
 *
 * Created on 26 de abril de 2022, 07:08 PM
 */

#ifndef APERTURADEARCHIVOS_H
#define APERTURADEARCHIVOS_H
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

// Funciones para abrir un archivo y verificar su apertura

// ********************************************************
// LA VARIABLE DE ARCHIVO NO DEBE INVOCAR AL CONSTUCTOR
// ********************************************************

void AperturaDeUnArchivoDeTextosParaLeer(ifstream &archivo, 
                                         const char*nombreDelArchivo);

void AperturaDeUnArchivoDeTextosParaEscribir(ofstream &archivo, 
                                             const char*nombreDelArchivo);

#endif /* APERTURADEARCHIVOS_H */


//
// Created by hecto on 8/28/2025.
//

#ifndef APERTURAARCHIVOS_APERTURADEARCHIVOS_HPP
#define APERTURAARCHIVOS_APERTURADEARCHIVOS_HPP

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

// Funciones para abrir un archivo y verificar su apertura

// ********************************************************
// LA VARIABLE DE ARCHIVO NO DEBE INVOCAR AL CONSTUCTOR
// ********************************************************

void AperturaDeUnArchivoDeTextosParaLeer(ifstream &archivo,
                                         const char *nombreDelArchivo);

void AperturaDeUnArchivoDeTextosParaEscribir(ofstream &archivo,
                                             const char *nombreDelArchivo);

#endif //APERTURAARCHIVOS_APERTURADEARCHIVOS_HPP

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "AperturaDeArchivos.h"

void AperturaDeUnArchivoDeTextosParaLeer(ifstream &archivo, const char*nombreDelArchivo){
    archivo.open(nombreDelArchivo, ios::in);
}

void AperturaDeUnArchivoDeTextosParaEscribir(ofstream &archivo, const char*nombreDelArchivo){
    archivo.open(nombreDelArchivo, ios::out);
}
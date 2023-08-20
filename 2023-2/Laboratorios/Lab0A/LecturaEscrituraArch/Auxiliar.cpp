/* 
 * File:   Auxiliar.cpp
 * Author: Jorge Fatama Vera (20143258)
 *
 * Created on 18 de agosto de 2023, 08:30 AM
 */
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include "Auxiliar.h"

void leerLibros(ifstream& archEntrada, ofstream& archSalida){
    char codigo[10];
    char nombreLibro[50];
    char nombreAutor[50];
    int nEjemplares;
    double precio;
    char aux;
    /* Leer cada libro hasta que encontremos el fin de archivo*/
    imprimirCabecera(archSalida);
    
    while(true){
        /* Lectura de código */
        archEntrada.getline(codigo, 10, ',');
        if(archEntrada.eof())
            break;
        /* Lectura de nombre del libro */
        archEntrada.getline(nombreLibro, 100, ',');
        /* Lectura de nombre del autor */
        archEntrada.getline(nombreAutor, 100, ',');
        // Opción 1: Trabajar con get()
        /*archEntrada >> nEjemplares;
        archEntrada.get();
        archEntrada >> precio;*/
        // Opción 2: Usar el objeto de archivo de entrada
        archEntrada >> nEjemplares >> aux >> precio;
        archEntrada.get();
        
        imprimirLibro(archSalida, codigo, nombreLibro, nombreAutor,
            nEjemplares, precio);
    }
}

void imprimirCabecera(ofstream& arch){
    arch << setw(10) << left << "CODIGO" << setw(40) << "LIBRO"
            << setw(40) <<  "AUTOR" << setw(12) << "EJEMPLARES"
            << setw(14) << right << "PRECIO (S/.)" << endl;
    imprimirLinea(arch, 116, '=');
}

void imprimirLibro(ofstream& arch, const char * codigo,
        const char * nombreLibro, const char * nombreAutor, int ejemplares,
        double precio){
    arch.precision(2);
    arch << setw(10) << left << codigo;
    imprimirCadena(arch, nombreLibro);
    imprimirCadena(arch, nombreAutor);
    arch << setw(8) << ' ' << setw(2) << right
                 << setfill('0') << ejemplares << setfill(' ')
                 << setw(16) << fixed << precio << endl;
}

void imprimirLinea(ofstream& arch, int nCaracteres, char repetidor){
    for(int i=0; i<nCaracteres; i++)
        arch << repetidor;
    arch << endl;
}

void imprimirCadena(ofstream& arch, const char* cadena){
    bool repetido = false;
    int nCaracteresImpresos = 0;
    
    for(int i=0; i<50; i++){
        if(cadena[i] == '\0')
            break;
        // Si el caracter es el espacio y ya hay un espacio repetido
        //  no hacer nada
        // Si el caracter es el espacio y no hay repetido, imprimirlo
        //  y cambiar la bandera repetido
        if(not(cadena[i] == ' ' and repetido)){      
            if(cadena[i] == ' ' and not repetido)
                repetido = true;
            if(cadena[i] != ' ' and repetido)
                repetido = false;
            arch << cadena[i];
            nCaracteresImpresos++;
        }
    }
    // Imprimir los espacios con los caracteres que sobran.
    for(int i=nCaracteresImpresos; i<40; i++) arch << ' ';
}
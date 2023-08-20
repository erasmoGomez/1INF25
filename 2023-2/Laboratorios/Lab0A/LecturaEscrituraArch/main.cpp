/* 
 * File:   main.cpp
 * Author: Jorge Fatama Vera (20143258)
 *
 * Created on 18 de agosto de 2023, 08:29 AM
 */

#include <iostream>
#include <fstream>
using namespace std;
#include "Auxiliar.h"

/*
 * 
 */
int main(int argc, char** argv) {
    // Declaración de un archivo de lectura
    ifstream archLibros("Libros.csv", ios::in);
    // Declaración de un archivo de escritura
    ofstream archReporte("Reporte.txt", ios::out);
    /* Validación de archivos */
    if(not archLibros.is_open()){
        cout << "ERROR al abrir archivo Libros.csv" << endl;
        exit(1);
    }
    if(not archReporte.is_open()){
        cout << "ERROR al abrir archivo Reporte.txt" << endl;
        exit(1);
    }
    leerLibros(archLibros, archReporte);
    return 0;
}


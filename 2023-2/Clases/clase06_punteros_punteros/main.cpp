/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Erasmo G. Montoya
 *
 * Created on August 29, 2023, 7:55 AM
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include "functions.hpp"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    //Definimos las estructuras a utilizar
    int* codigo;
    char** nombre;
    char*** cursos;
    cargar_alumnos(codigo, nombre, cursos, "Alumnos-Cursos.csv");
    reporte_alumnos(codigo, nombre, cursos, "reporte_alumnos.txt");
    return 0;
}


/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Erasmo G. Montoya
 *
 * Created on September 2, 2024, 5:47 PM
 */
#include "funciones.hpp"
/*
 * 
 */
int main(int argc, char** argv) {
    int* codigos;
    char** nombres;
    char*** cursos;
    cargar_alumnos(codigos, nombres, "Alumnos.csv");
    cargar_cursos(codigos,cursos,"Cursos.csv");
    imprimir_alumnos(codigos, nombres, "reporte.txt");
    return 0;
}


/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Erasmo Gomez
 *
 * Created on April 2, 2025, 4:26 PM
 */

#include "funciones.hpp"

/*
 * 
 */
int main(int argc, char** argv) {
    int* codigos;
    char** nombres;
    char*** cursos;
    cargar_alumnos_incrementos(codigos, nombres, "Alumnos.csv");
    imprimir_alumnos(codigos, nombres, "reporte.txt");
    cargar_cursos_incrementos(codigos, cursos, "Cursos.csv");
    imprimir_alumnos(codigos, nombres, cursos, "reporte_completo.txt");

    return 0;
}


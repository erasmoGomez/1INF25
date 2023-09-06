/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Erasmo G. Montoya
 *
 * Created on September 5, 2023, 7:47 AM
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include "funciones.hpp"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    char **alumno_nombre, **curso_nombre;
    char *alumno_modalidad;
    int *alumno_codigo;
    int *alumno_porcentaje;
    int *alumno_escala;
    int **curso_alumnos;
    double *curso_credito;
    
    lectura_alumnos("alumnos.csv",alumno_codigo, alumno_nombre,alumno_modalidad,
                    alumno_porcentaje,alumno_escala);
    prueba_lectura_alumnos("reporte_alumnos.txt",alumno_codigo, alumno_nombre,
                    alumno_modalidad,alumno_porcentaje,alumno_escala);
    lectura_cursos("alumnos_cursos.csv",alumno_codigo,alumno_escala, curso_nombre, 
                    curso_credito, curso_alumnos);
    prueba_lectura_cursos("report_cursos.txt",curso_nombre, curso_credito, curso_alumnos);
    return 0;
}


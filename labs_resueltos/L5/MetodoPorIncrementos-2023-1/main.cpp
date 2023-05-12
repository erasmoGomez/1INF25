/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Jorge Fatama Vera (jorge.fatama@pucp.edu.pe)
 *
 * Created on 12 de mayo de 2023, 09:05
 */

#include "MetodoPorIncrementos.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    char ***cursos_datos, ****cursos_alumnos;
    int *cursos_credito;
    double **cursos_informacion_economica;
    
    cargarDatos("matricula_ciclo_2023_1.csv", cursos_datos, cursos_credito,
            cursos_alumnos, cursos_informacion_economica);
    pruebaCursos("PruebaCursos.txt", cursos_datos, cursos_credito,
            cursos_alumnos, cursos_informacion_economica);
    reporteDeAlumnosPorCurso("ReporteDeAlumnosPorCurso.txt", cursos_datos, cursos_credito,
            cursos_alumnos, cursos_informacion_economica);
    return 0;
}


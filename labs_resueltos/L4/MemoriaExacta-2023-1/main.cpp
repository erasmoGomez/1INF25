/* 
 * File:   main.cpp
 * Author: Jorge Fatama Vera
 *
 * Created on 5 de mayo de 2023, 08:13 AM
 */

#include "MetodoDinamicoExacto.h"
int main(int argc, char** argv) {
    char **alumno_Nombre, **curso_Nombre, *alumno_Modalidad;
    int *alumno_Codigo, *alumno_Porcentaje, *alumno_Escala;
    int **curso_Alumnos;
    double *curso_Credito;
    lecturaAlumnos("alumnos.csv", alumno_Codigo, alumno_Nombre, 
            alumno_Modalidad, alumno_Porcentaje, alumno_Escala);
    pruebaLecturaAlumnos("ReporteAlumnos.txt", alumno_Codigo, alumno_Nombre, 
            alumno_Modalidad, alumno_Porcentaje, alumno_Escala);
    lecturaCursos("alumnos_cursos.csv", alumno_Codigo, alumno_Escala, 
            curso_Nombre, curso_Credito, curso_Alumnos);
    pruebaDeLecturaCursos("ReporteCursos.txt", curso_Nombre, curso_Credito,
            curso_Alumnos);
    reporteDeRecaudacionPorModalidad("ReporteRecaudacionModalidad.txt", 
            alumno_Codigo, alumno_Modalidad, alumno_Porcentaje, alumno_Nombre,
            curso_Nombre, curso_Credito, curso_Alumnos);
    return 0;
}


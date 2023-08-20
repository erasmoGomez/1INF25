/* 
 * File:   main.cpp
 * Author: Jorge Fatama
 *
 * Created on 29 de abril de 2023, 04:05
 */

#include "AperturaDeArchivos.h"
#include "AuxBiblio.h"
#include "PruebaBiblio.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    // Declaración de variables relacionadas a archivos.
    ifstream archCursos, archAlumnos, archMatricula;
    ofstream archReporte;
    // Declaración de variables relacionadas a estructuras.
    struct StCurso curso, cursos[20];
    struct StAlumno alumno, alumnos[20];
    // Apertura de archivos
    AperturaDeUnArchivoDeTextosParaLeer(archCursos, "Cursos.txt");
    AperturaDeUnArchivoDeTextosParaLeer(archAlumnos, "Alumnos.txt");
    AperturaDeUnArchivoDeTextosParaLeer(archMatricula, "Matricula.txt");
    AperturaDeUnArchivoDeTextosParaEscribir(archReporte, "Reporte.txt");
    // Pruebas
    probarCurso(archCursos, archReporte, cursos, curso);
    probarAlumno(archAlumnos, archReporte, alumnos, alumno);
    probarMatricula(archMatricula, archReporte, cursos, alumnos, 
            curso, alumno);
    return 0;
}


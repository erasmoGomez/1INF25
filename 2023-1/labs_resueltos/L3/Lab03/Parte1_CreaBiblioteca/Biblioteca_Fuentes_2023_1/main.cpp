/* 
 * File:   main.cpp
 * Author: Jorge Fatama Vera <jorge.fatama@pucp.edu.pe>
 *
 * Created on 28 de abril de 2023, 08:41 AM
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
    struct StCurso curso, cursos[10];
    struct StAlumno alumno, alumnos[100];
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


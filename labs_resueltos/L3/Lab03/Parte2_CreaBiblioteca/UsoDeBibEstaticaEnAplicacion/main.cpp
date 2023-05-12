/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Jorge Fatama
 *
 * Created on 29 de abril de 2023, 04:10
 */

#include "Auxiliar.h"
using namespace std;

int main(int argc, char** argv) {
    // Declaración de variables relacionadas a archivos.
    ifstream archCursos, archAlumnos, archMatricula;
    ofstream archReporte;
    // Declaración de variables relacionadas a estructuras.
    struct StCurso cursos[10];
    struct StAlumno alumnos[100];
    // Apertura de archivos
    AperturaDeUnArchivoDeTextosParaLeer(archCursos, "Cursos.txt");
    AperturaDeUnArchivoDeTextosParaLeer(archAlumnos, "Alumnos.txt");
    AperturaDeUnArchivoDeTextosParaLeer(archMatricula, "Matricula.txt");
    AperturaDeUnArchivoDeTextosParaEscribir(archReporte, "Reporte.txt");
    // Lectura de archivos
    leerCursos(archCursos, cursos);
    leerAlumnos(archAlumnos, alumnos);
    leerMatriculas(archMatricula, cursos, alumnos);
    calcularCostos(cursos, alumnos);
    imprimirReporte(archReporte, cursos, alumnos);
    return 0;
}


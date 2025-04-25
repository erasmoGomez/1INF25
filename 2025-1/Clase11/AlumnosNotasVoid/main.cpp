/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Erasmo Gomez
 * Description: 
 * Created on April 16, 2025, 4:23 PM
 */

#include "funciones_genericas.hpp"

/*
 * 
 */
int main(int argc, char** argv) {
    void *alumnos;
    cargar_alumnos(alumnos, "Alumnos.csv");
    cargar_notas(alumnos, "CursosNotas.csv");
    calcular_promedio(alumnos);
    probar_carga(alumnos, "reporte.txt");
    ordenar(alumnos);
    probar_carga(alumnos, "reporte_ordenado.txt");
    return 0;
}


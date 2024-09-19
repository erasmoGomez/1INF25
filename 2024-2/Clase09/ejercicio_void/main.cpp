/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Erasmo G. Montoya
 *
 * Created on September 16, 2024, 6:09 PM
 */

#include "funcines_genericas.hpp"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    void *alumnos;
    cargar_alumnos(alumnos, "Alumnos.csv");
//    cargarNotas(alumnos, "CursosNotas.csv");
//    calcularPromedios(alumnos);
    probar_carga(alumnos, "reporte.txt");
    ordenar(alumnos);
//    cout << endl << endl << "Alumnos ordenados" << endl;
    probar_carga(alumnos,"reporte_ordenado.txt");
//    eliminarDatos(alumnos);
    return 0;
}

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
    //ordenar(alumnos);
    //probar_carga(alumnos, "reporte_ordenado.txt");
    int cantidad = 0;
    cantidad = obtener_cantidad(alumnos);
//    qsort(alumnos, cantidad, sizeof(void*), compara_cadenas);
//    probar_carga(alumnos, "reporte_ordenado_qsort.txt");
    
    quick_sort_generico(alumnos, 0, cantidad - 1, comparar_orden_generico);
    probar_carga(alumnos, "reporte_ordenado_qsort_generico.txt");
//    int arr[10]{9,4,6,2,25,6,1,7,1,67};
//    qsort(arr, 10, sizeof(int), compara_enteros);
    return 0;
}


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
    int cantidad = 0;
    cargar_alumnos(alumnos, "Alumnos.csv");
    //cargarNotas(alumnos, "CursosNotas.csv");
    //calcular_promedios(alumnos);
    //probar_carga(alumnos, "reporte.txt");
    //ordenar(alumnos);
    cantidad = obtener_cantidad(alumnos);
    //qsort(alumnos, cantidad, sizeof(void*), compara_cadenas);
    quick_sort_generico(alumnos, 0, cantidad -1, comparar_orden_generico);
    probar_carga(alumnos,"reporte_ordenado_generico.txt");
//    eliminarDatos(alumnos);
    return 0;
}

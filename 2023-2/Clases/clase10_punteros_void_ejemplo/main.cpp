/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Erasmo G. Montoya
 *
 * Created on September 13, 2023, 7:44 AM
 */

#include "funciones.hpp"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    void *alumnos;
    cargar_alumnos(alumnos);
    probar_alumnos(alumnos);
    cargar_notas(alumnos);
    calcular_promedios(alumnos);
    return 0;
}


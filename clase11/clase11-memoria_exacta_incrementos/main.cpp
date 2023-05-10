/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: erasmog
 *
 * Created on May 9, 2023, 12:43 AM
 */

#include "funciones.hpp"

/*
 * 
 */
int main(int argc, char** argv) {
    int *codigo;
    char **nombre, ***cursos;

    cargarAlumnos(codigo,nombre,cursos);
    //reporteDeAlumnos(codigo,nombre,cursos);

    return 0;
}


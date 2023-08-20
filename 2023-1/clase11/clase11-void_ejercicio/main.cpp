/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: erasmog
 *
 * Created on May 9, 2023, 3:00 AM
 */

#include "funciones.hpp"

/*
 * 
 */
int main(int argc, char** argv) {
    void *alumno;
    cargar_alumnos(alumno);
    reporte_alumnos(alumno);
    return 0;
}


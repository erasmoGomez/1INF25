/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Erasmo G. Montoya
 *
 * Created on October 4, 2023, 7:28 AM
 */

#include "funciones_auxiliares.hpp"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int *codigos;
    int *fechas;
    char **titulos;
    char **salones;
    int *aforos;
    cargar_eventos("infosoft_eventos.csv", codigos, fechas, titulos, salones, aforos);
    ordenar_eventos(codigos, fechas, titulos, salones, aforos);
    //busqueda_eventos();
    return 0;
}


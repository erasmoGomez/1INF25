/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: erasmog
 *
 * Created on June 27, 2023, 9:05 PM
 */

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
#include "lista.hpp"
#include "persona.hpp"

/*
 * 
 */
int main(int argc, char** argv) {
    class Lista<int> listaInt;
    listaInt.crea("datos_int.txt");
    listaInt.imprimir("reporte_int.txt");

    class Lista<string> listaStr;
    listaStr.crea("datos_nombres.txt");
    listaStr.imprimir("reporte_nombres.txt");

    class Lista<class Persona> listaPer;
    listaPer.crea("datos_persona.csv");
    listaPer.imprimir("reporte_persona.txt");

    return 0;
}


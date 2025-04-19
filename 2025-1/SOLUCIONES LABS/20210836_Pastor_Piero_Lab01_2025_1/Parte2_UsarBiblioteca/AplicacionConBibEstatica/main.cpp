/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: piero
 *
 * Created on 15 de abril de 2025, 07:55 AM
 */

#include <cstdlib>
#include "FuncionesSolucion.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int *dni;
    struct CadenaDeCaracteres *conductor, *placa;
    LeerDatos("datos.txt", dni, conductor, placa);
    OrdenarDatos(dni, conductor, placa);
    ImprimirReporte("reporte.txt", dni, conductor, placa);
    return 0;
}


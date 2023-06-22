/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
#include "farmacia.hpp"
#include "conreceta.hpp"
#include "sinreceta.hpp"
using namespace std;

void Farmacia::leer_recetas() {
    // Apertura de archivo para lectura
    const char* nombreArch = "recetas2.csv";
    ifstream archRecetas(nombreArch, ios::in);
    if (!archRecetas) {
        cout << "ERROR: No se puede abrir el archivo " << nombreArch << endl;
        exit(1);
    }

    carga_recetas(archRecetas);
}

void Farmacia::carga_recetas(ifstream& archRecetas) {
    int nd=0;
    // Lectura
    while (true) {
        loferta[nd].asigna_medicamento(archRecetas);
        if (archRecetas.eof())break;
        nd++;
    }
    loferta[nd] = nullptr;
}

void Farmacia::imprime_recetas() {
    // Apertura de archivo para escritura
    const char* nombreArch = "Reporte.txt";
    ofstream archReporte(nombreArch, ios::out);
    if (!archReporte) {
        cout << "ERROR: " << nombreArch;
        exit(1);
    }

    imprime_reporte(archReporte);
}

void Farmacia::imprime_cabecera(ofstream& archReporte) {
    archReporte << setw(95) << "REPORTE DE DEUDAS" << endl;
    imprime_linea(archReporte, 220, '=');
    archReporte << "Fecha" << setw(21) << "Cod. Med"
            << setw(29) << "Nombre de Medicina" << setw(48)
            << "Cant." << setw(17) << "Precio" << setw(16) << "Total"
            << setw(20) << "DNI/Codigo" << setw(30) << "Nombre/Especialidad" << endl;
    imprime_linea(archReporte, 220, '=');
}

void Farmacia::imprime_reporte(ofstream& archReporte) {
    // Imprime cabecera
    imprime_cabecera(archReporte);

    for (int i = 0; loferta[i] != nullptr; i++) {
        loferta[i].imprime_medicamento(archReporte); //USAMOS POLIMORFISMO
    }
}

void Farmacia::imprime_linea(ofstream& archReporte, int cantidad, char car) {
    for (int i = 0; i < cantidad; i++) archReporte << car;
    archReporte << endl;
}
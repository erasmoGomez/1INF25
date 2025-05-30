/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Biblioteca.cpp
 * Author: hecto
 * 
 * Created on May 28, 2025, 4:51 PM
 */

#include "Biblioteca.hpp"

Biblioteca::Biblioteca() {
    cantidad_estantes = 0;
    cantidad_libros = 0;
}

Biblioteca::Biblioteca(const Biblioteca& orig) {
}

Biblioteca::~Biblioteca() {
}

void Biblioteca::SetCantidad_libros(int cantidad_libros) {
    this->cantidad_libros = cantidad_libros;
}

int Biblioteca::GetCantidad_libros() const {
    return cantidad_libros;
}

void Biblioteca::SetCantidad_estantes(int cantidad_estantes) {
    this->cantidad_estantes = cantidad_estantes;
}

int Biblioteca::GetCantidad_estantes() const {
    return cantidad_estantes;
}

void Biblioteca::cargar_libros() {
    ifstream input("libros.csv", ios::in);
    int n=0;
    while(true){
        Libro libro;
        input>>libro;
        if(input.eof())break;
        libros[n] = libro;
        n++;
    }
    SetCantidad_libros(n);
}

void Biblioteca::cargar_estantes() {
    ifstream input("estantes.csv", ios::in);
    int n=0;
    while(true){
        Estante estante;
        input>>estante;
        if(input.eof())break;
        estantes[n] = estante;
        n++;
    }
    SetCantidad_estantes(n);
}

void Biblioteca::posicionar_libros() {
    for (int j = 0; j < cantidad_libros; ++j) {
        for (int i = 0; i < cantidad_estantes; ++i) {
            if (estantes[i] += libros[j]) {
                break; // Libro colocado, pasa al siguiente
            }
        }
    }
}

void Biblioteca::imprime_linea(ofstream& output, int n, char c) {
    output << setfill(c) << setw(n) << " " << endl;
    output << setfill(' ');
}

void Biblioteca::mostrar_datos() {

    ofstream output("reporte.txt", ios::out);
    imprime_linea(output, 50, '=');
    output << right << setw(45) << "Informacion del posicionamiento de Libros" << endl;
    output << right << setw(40) << "en los estantes de la Biblioteca " << endl;
    imprime_linea(output, 50, '=');
    output << "Cantidad de Estantes: " << cantidad_estantes << endl;
    for (int i = 0; i < cantidad_estantes; i++)
        output << estantes[i];
    imprime_linea(output, 50, '=');
    output << "Informacion de todos los Libros: " << endl;
    output << "Cantidad de Libros Total: " << cantidad_libros << endl;
    for (int i = 0; i < cantidad_libros; i++)
        output<<libros[i];
    imprime_linea(output, 50, '=');
    output << endl;
}

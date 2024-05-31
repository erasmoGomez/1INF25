/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Biblioteca.cpp
 * Author: Erasmo G. Montoya
 * 
 * Created on May 23, 2024, 10:14 PM
 */

#include "Biblioteca.hpp"

Biblioteca::Biblioteca() {
    n_libros = 0;
    n_estantes = 0;
}

int Biblioteca::getNEstantes() const {
    return n_estantes;
}

void Biblioteca::setNEstantes(int nEstantes) {
    n_estantes = nEstantes;
}

int Biblioteca::getNLibros() const {
    return n_libros;
}

void Biblioteca::setNLibros(int nLibros) {
    n_libros = nLibros;
}

void Biblioteca::cargar_libros() {
    ifstream input("libros.csv", ios::in);
    int n = 0;

    while (true) {
        Libro libro;
        input>>libro;
        if (input.eof())break;
        libros[n] = libro;
        n++;
    }
    setNLibros(n);
}

void Biblioteca::cargar_estantes() {
    ifstream input("estantes.csv", ios::in);
    int n = 0;

    while (true) {
        Estante estante;
        input>>estante;
        if (input.eof())break;
        estantes[n] = estante;
        n++;
    }
    setNEstantes(n);
}

void Biblioteca::posicionar_libros() {
    int flag = 0;
    for (int i = 0; i < n_estantes; i++) {
        for (int j = flag; j < n_libros; j++) {
            if (estantes[i] += libros[j]) {
                continue;
            } else {
                flag = j;
                break;
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
    output << "Cantidad de Estantes: " << n_estantes << endl;
    for (int i = 0; i < n_estantes; i++)
        output << estantes[i];
    imprime_linea(output, 50, '=');
    output << "Informacion de todos los Libros: " << endl;
    output << "Cantidad de Libros Total: " << n_libros << endl;
    for (int i = 0; i < n_libros; i++)
        libros[i].muestra(output);
    imprime_linea(output, 50, '=');
    output << endl;
}


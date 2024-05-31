/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Biblioteca.hpp
 * Author: Erasmo G. Montoya
 *
 * Created on May 23, 2024, 10:14 PM
 */

#ifndef BIBLIOTECA_HPP
#define BIBLIOTECA_HPP

#include "Utils.hpp"
#include "Libro.hpp"
#include "Estante.hpp"
using namespace std;

class Biblioteca {
private:
    Estante estantes[10];
    Libro libros[10];
    int n_estantes;
    int n_libros;
public:
    Biblioteca();
    void cargar_libros();
    void cargar_estantes();
    void posicionar_libros();
    void mostrar_datos();
    int getNEstantes() const;

    void setNEstantes(int nEstantes);

    int getNLibros() const;

    void setNLibros(int nLibros);
    
    void imprime_linea(ofstream&, int, char);
};

#endif /* BIBLIOTECA_HPP */


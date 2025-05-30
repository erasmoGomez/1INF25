/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Biblioteca.hpp
 * Author: hecto
 *
 * Created on May 28, 2025, 4:51 PM
 */

#ifndef BIBLIOTECA_HPP
#define BIBLIOTECA_HPP
#include "Estante.hpp"
#include "Libro.hpp"

class Biblioteca {
public:
    Biblioteca();
    Biblioteca(const Biblioteca& orig);
    virtual ~Biblioteca();
    void SetCantidad_libros(int cantidad_libros);
    int GetCantidad_libros() const;
    void SetCantidad_estantes(int cantidad_estantes);
    int GetCantidad_estantes() const;
    
    void cargar_libros();
    void cargar_estantes();
    void posicionar_libros();
    void mostrar_datos();
    void imprime_linea(ofstream&, int, char);
    
private:
    Estante estantes[10];
    Libro libros[10];
    int cantidad_estantes;
    int cantidad_libros;
};

#endif /* BIBLIOTECA_HPP */


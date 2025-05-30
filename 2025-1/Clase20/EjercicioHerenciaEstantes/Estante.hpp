/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Estante.hpp
 * Author: hecto
 *
 * Created on May 28, 2025, 4:38 PM
 */

#ifndef ESTANTE_HPP
#define ESTANTE_HPP
#include "Espacio.hpp"
#include "Libro.hpp"

class Estante {
public:
    Estante();
    Estante(const Estante& orig);
    virtual ~Estante();
    void SetCantidad_libros(int cantidad_libros);
    int GetCantidad_libros() const;
    void SetAltura(int altura);
    int GetAltura() const;
    void SetAnchura(int anchura);
    int GetAnchura() const;
    void SetCodigo(const char*);
    void GetCodigo(char*) const;
    
    void leer(ifstream&);
    void mostrar(ofstream&)const;
    void imprime_linea(ofstream&, int, char) const;
    void pinta_estante(ofstream&) const;
    int get_espacios_restantes();
    void colocar_libro(int, Libro&);
    bool operator+=(Libro&);
private:
    char* codigo;
    int anchura;
    int altura;
    Libro libros[10];
    int cantidad_libros;
    Espacio *espacios;
};

void operator>>(ifstream& input, Estante &);
void operator<<(ofstream& output, const Estante &);
#endif /* ESTANTE_HPP */


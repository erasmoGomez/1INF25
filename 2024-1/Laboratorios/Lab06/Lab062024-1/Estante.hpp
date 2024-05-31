/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Estante.hpp
 * Author: Erasmo G. Montoya
 *
 * Created on May 23, 2024, 10:18 PM
 */

#ifndef ESTANTE_HPP
#define ESTANTE_HPP

#include "Utils.hpp"
#include "Libro.hpp"
#include "Espacio.hpp"
using namespace std;

class Estante {
private:
    char* codigo;
    int anchura;
    int altura;
    Libro libros[10];
    int cantidad_libros;
    Espacio *espacios;
public:
    void getCodigo(char *) const;

    void setCodigo(const char *codigo);

    int getAnchura() const;

    void setAnchura(int anchura);

    int getAltura() const;

    void setAltura(int altura);

    int getCantidadLibros() const;

    void setCantidadLibros(int cantidadLibros);

    void lee(ifstream&);

    void muestra(ofstream&);

    void colocar_libro(int, Libro&);

    int get_espacios_restantes();

    void pinta_estante(ofstream&);

    Estante();

    bool operator+=(Libro&);
    
    void imprime_linea(ofstream&, int, char);
};

void operator>>(ifstream&, Estante&);
void operator<<(ofstream&, Estante);

#endif /* ESTANTE_HPP */


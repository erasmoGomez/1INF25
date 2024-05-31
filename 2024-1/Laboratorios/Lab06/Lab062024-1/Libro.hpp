/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Libro.hpp
 * Author: Erasmo G. Montoya
 *
 * Created on May 23, 2024, 10:21 PM
 */

#ifndef LIBRO_HPP
#define LIBRO_HPP

#include "Utils.hpp"
using namespace std;

class Libro {
private:
    char* nombre;
    int alto;
    int ancho;
    char* codigo;
    bool colocado;
public:
    void getCodigo(char *) const;

    void setCodigo(const char *codigo);

    void getNombre(char *) const;

    void setNombre(const char *nombre);

    int getAlto() const;

    void setAlto(int alto);

    int getAncho() const;

    void setAncho(int ancho);
    
    bool getColocado() const;

    void setColocado(bool colocado);

    void lee(ifstream&);

    void muestra(ofstream&);

    Libro();
};

void operator>>(ifstream&, Libro&);
void operator<<(ofstream&, Libro);

#endif /* LIBRO_HPP */


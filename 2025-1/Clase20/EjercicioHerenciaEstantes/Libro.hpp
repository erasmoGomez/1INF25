/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Libro.hpp
 * Author: hecto
 *
 * Created on May 28, 2025, 4:18 PM
 */


#ifndef LIBRO_HPP
#define LIBRO_HPP
#include "Utils.hpp"
class Libro {
public:
    Libro();
    Libro(const Libro& orig);
    virtual ~Libro();
    void SetColocado(bool colocado);
    bool IsColocado() const;
    void SetAlto(int alto);
    int GetAlto() const;
    void SetAncho(int ancho);
    int GetAncho() const;
    void SetNombre(const char* nombre);
    void GetNombre(char*) const;
    void SetCodigo(const char* codigo);
    void GetCodigo(char*) const;
    
    void leer(ifstream&);
    void mostrar(ofstream&)const;
   
private:
    char* codigo;
    char* nombre;
    int ancho;
    int alto;
    bool colocado;
};

void operator>>(ifstream& input, Libro &);
void operator<<(ofstream& output, const Libro &);
#endif /* LIBRO_HPP */


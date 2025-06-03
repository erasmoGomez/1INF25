/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Personaje.hpp
 * Author: hecto
 *
 * Created on May 30, 2025, 5:20 AM
 */

#ifndef PERSONAJE_HPP
#define PERSONAJE_HPP
#include "Utils.hpp"
class Personaje {
public:
    Personaje(const char*, int );
    Personaje();
    Personaje(const Personaje& orig); //Constructor Copia
    virtual ~Personaje();
    
    void setNivel(int nivel);
    int getNivel() const;
    void setNombre(const char* nombre);
    void getNombre(char*) const;
    void operator=(const Personaje& otro); //Sobrecarga del Operador =
    
    virtual void mostrar() const; //Metodo Polimorfico
    virtual void leer(ifstream&);
    virtual void realizar_accion();
    virtual void realizar_accion_pura() = 0;
private:
    char* nombre;
    int nivel;
};

#endif /* PERSONAJE_HPP */


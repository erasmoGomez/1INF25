/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Guerrero.hpp
 * Author: hecto
 *
 * Created on May 30, 2025, 5:20 AM
 */

#ifndef GUERRERO_HPP
#define GUERRERO_HPP
#include "Personaje.hpp"
class Guerrero:public Personaje {
public:
    Guerrero();
    Guerrero(const Guerrero& orig);
    virtual ~Guerrero();
    Guerrero(const char* nombre_in, int nivel_in, int fuerza_in);
    void mostrar() const;
    void leer(ifstream&);
private:
    int fuerza;
};

#endif /* GUERRERO_HPP */


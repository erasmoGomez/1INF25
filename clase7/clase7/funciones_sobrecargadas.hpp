/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   funciones_sobrecargadas.hpp
 * Author: erasmog
 *
 * Created on April 18, 2023, 8:47 AM
 */

#ifndef FUNCIONES_SOBRECARGADAS_HPP
#define FUNCIONES_SOBRECARGADAS_HPP
#include "funciones.hpp"
struct Persona& operator +(const struct Persona &,const struct Persona &);
void operator *(struct Persona &, double);
ostream & operator <<(ostream &, const struct Persona &);
ifstream & operator >> (ifstream &, struct Persona &);

#endif /* FUNCIONES_SOBRECARGADAS_HPP */


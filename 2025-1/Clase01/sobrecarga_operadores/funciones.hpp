/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   funciones.hpp
 * Author: hecto
 *
 * Created on March 25, 2025, 6:36 PM
 */

#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP
#include "persona.hpp"

ostream & operator <<(ostream &, const struct Persona&);
istream & operator >> (istream &, struct Persona&);

void operator += (struct Persona&, double porcentaje);

#endif /* FUNCIONES_HPP */


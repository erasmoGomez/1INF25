/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   sobrecargas.hpp
 * Author: hecto
 *
 * Created on March 26, 2025, 5:21 PM
 */

#ifndef SOBRECARGAS_HPP
#define SOBRECARGAS_HPP
#include "utils.hpp"
#include "estructuras.hpp"

ostream& operator << (ostream&, const struct Papeleta&); //Aqui va con const
ofstream& operator << (ofstream&, const struct Papeleta&); //Aqui va con const
ifstream& operator >> (ifstream&, struct Papeleta&);
int leer_fecha(ifstream&);
char* leer_cadena(ifstream&, char = ',');
ifstream& operator >> (ifstream&, struct Conductor&);
ostream& operator << (ostream&, const struct Conductor&); //Aqui va con const
ofstream& operator << (ofstream&, const struct Conductor&); //Aqui va con const

bool operator<(const Conductor&, int dni);

void operator+=(Conductor& ,const Papeleta&);

#endif /* SOBRECARGAS_HPP */


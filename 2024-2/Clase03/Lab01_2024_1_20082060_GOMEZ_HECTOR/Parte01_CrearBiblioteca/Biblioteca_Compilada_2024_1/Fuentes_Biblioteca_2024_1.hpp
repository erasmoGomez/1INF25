/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Fuentes_Biblioteca_2024_1.hpp
 * Author: Erasmo G. Montoya
 *
 * Created on August 26, 2024, 6:12 PM
 */

#ifndef FUENTES_BIBLIOTECA_2024_1_HPP
#define FUENTES_BIBLIOTECA_2024_1_HPP
#include "utils.hpp"
using namespace std;

bool operator >>(ifstream &, struct Libro &);     
bool operator >>(ifstream &, struct Cliente &);
bool operator >>(struct LibroSolicitado &, struct Libro *);
bool operator << (struct Cliente &, struct LibroSolicitado);
void operator ++(struct Cliente &);
void operator<<(ofstream &, struct Cliente);
void operator<<(ofstream &, struct Libro);

#endif /* FUENTES_BIBLIOTECA_2024_1_HPP */


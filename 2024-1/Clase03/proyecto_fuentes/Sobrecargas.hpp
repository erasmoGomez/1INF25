/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Sobrecargas.hpp
 * Author: ASUS
 *
 * Created on March 20, 2024, 8:20 AM
 */

#ifndef SOBRECARGAS_HPP
#define SOBRECARGAS_HPP

#include "Utils.hpp"
#include "Persona.hpp"
using namespace std;
ostream & operator << (ostream &, const struct Persona &);
ofstream & operator << (ofstream &, const struct Persona &);
ifstream & operator >> (ifstream &, struct Persona &);
#endif /* SOBRECARGAS_HPP */


/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Sobrecargas.hpp
 * Author: ASUS
 *
 * Created on March 25, 2024, 6:21 PM
 */

#ifndef SOBRECARGAS_HPP
#define SOBRECARGAS_HPP
#include "Utils.hpp"
#include "Persona.hpp"
using namespace std;
// ifstream & operator >> (ifstream &, struct Persona &);
bool operator >> (ifstream &, struct Persona &);
ostream & operator << (ostream & out, const struct Persona & p);
#endif /* SOBRECARGAS_HPP */


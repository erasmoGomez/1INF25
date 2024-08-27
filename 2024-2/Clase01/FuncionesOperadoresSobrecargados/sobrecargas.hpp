/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   sobrecargas.hpp
 * Author: Erasmo G. Montoya
 *
 * Created on August 20, 2024, 6:52 PM
 */

#ifndef SOBRECARGAS_HPP
#define SOBRECARGAS_HPP

#include "Utils.hpp"
using namespace std;

//ifstream & operator >> (ifstream&, struct Telefono&);
ofstream & operator << (ofstream&, const struct Telefono&);

//istream & operator >> (istream&, struct Telefono&);
ostream & operator << (ostream&, const struct Telefono&);
bool operator >> (ifstream&, struct Telefono&);

//bool operator += (struct Telefono *&, struct Telefono &);
void operator *= (struct Telefono &, double);
#endif /* SOBRECARGAS_HPP */


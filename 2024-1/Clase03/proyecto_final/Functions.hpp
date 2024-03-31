/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Functions.hpp
 * Author: ASUS
 *
 * Created on March 20, 2024, 8:03 AM
 */

#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include "Utils.hpp"
#include "Persona.hpp"
using namespace std;

int add(int = 7, int = 10);
void add_headers();
void add_headers(ofstream &);
void read_people(ifstream &, Persona *);
void display_people(ofstream &, Persona *);

#endif /* FUNCTIONS_HPP */


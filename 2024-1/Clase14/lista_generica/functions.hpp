/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   functions.hpp
 * Author: ASUS
 *
 * Created on April 25, 2024, 8:14 AM
 */

#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP
#include "utils.hpp"
using namespace std;
void crear_lista(void*, void*(*lee)(ifstream&), int(*cmp)(const void*, const void*));
void* leer_registro(ifstream&);
int cmp_registro(const void*, const void*);

#endif /* FUNCTIONS_HPP */


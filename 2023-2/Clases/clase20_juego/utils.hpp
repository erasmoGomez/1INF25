/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   utils.hpp
 * Author: ASUS
 *
 * Created on October 18, 2023, 8:12 AM
 */

#ifndef UTILS_HPP
#define UTILS_HPP
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <sstream>
#define COLUMN_SIZE 10
#define N_COLUMNS 4
using namespace std;

void imprime_linea(ofstream &, int);
void imprime_headers(ofstream &, const char*, const char*);
#endif /* UTILS_HPP */


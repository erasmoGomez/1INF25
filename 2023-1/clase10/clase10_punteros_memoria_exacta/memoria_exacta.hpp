/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   memoria_exacta.hpp
 * Author: erasmog
 *
 * Created on May 2, 2023, 7:47 AM
 */

#ifndef MEMORIA_EXACTA_HPP
#define MEMORIA_EXACTA_HPP
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;

void cargar_artistas(char **&, char **&);
void probar_lectura_artistas(char **, char **);
char * memoria_exacta_cadena(char *);
void cargar_canciones(char **, char **&, int **&, double **&, char ***&);
#endif /* MEMORIA_EXACTA_HPP */


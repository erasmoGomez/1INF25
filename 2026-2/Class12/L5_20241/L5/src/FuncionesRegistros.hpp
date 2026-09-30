/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FuncionesRegistros.hpp
 * Author: Erasmo G. Montoya
 *
 * Created on October 1, 2024, 4:55 PM
 */

#ifndef FUNCIONESREGISTROS_HPP
#define FUNCIONESREGISTROS_HPP
#include "utils.hpp"
void *leeregistro(ifstream &arch);
char *leecadena(ifstream &arch, int max, char delim);
void imprimeregistro(ofstream &arch, void *registro);
int cmpregistro(void *reg1, void *reg2);

#endif /* FUNCIONESREGISTROS_HPP */


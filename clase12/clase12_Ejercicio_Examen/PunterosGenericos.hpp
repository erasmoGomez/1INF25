/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PunterosGenericos.hpp
 * Author: Erasmo Montoya
 *
 * Created on 10 de mayo de 2023, 3:04
 */

#ifndef PUNTEROSGENERICOS_HPP
#define PUNTEROSGENERICOS_HPP

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;


void cargaproductos(void *&);
void cargapedidos(void *&);
void procesaclientes(void *&, void *&, void *&);
void imprimereporte(void *&);
void * crear_producto(int,char *,double,int);
void * crear_predido(int ,const char *,int , int ,int ,char );
void imprimePedidos(void *&);

#endif /* PUNTEROSGENERICOS_HPP */

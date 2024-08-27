/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   funciones.hpp
 * Author: Erasmo G. Montoya
 *
 * Created on August 23, 2024, 9:14 AM
 */

#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP
#include "Utils.hpp"
#include "Telefono.hpp"
#include "sobrecargas.hpp"
using namespace std;
void leer_telefonos(ifstream&, struct Telefono *);
void imprimir_telefonos(ofstream&, struct Telefono *);
void incrementar_precios(struct Telefono *);
#endif /* FUNCIONES_HPP */


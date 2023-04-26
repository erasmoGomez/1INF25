/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   sobrecargas.hpp
 * Author: erasmog
 *
 * Created on April 26, 2023, 7:26 AM
 */

#ifndef SOBRECARGAS_HPP
#define SOBRECARGAS_HPP
#include <iostream>
#include <cstring>
#include <fstream>
#include "AperturaDeArchivos.h"
#include "Estructuras.h"
using namespace std;

ifstream & operator >>(ifstream &, struct Estructura_ClienteRegistrado &);
void operator +=(struct Estructura_ClienteRegistrado *, const struct Estructura_ClienteRegistrado &);
void operator +=(struct Estructura_ClienteRegistrado &, const struct Estructura_PedidoRealizado &);
void operator +=(struct Estructura_ProductosEnAlmacen * , const struct Estructura_ProductosEnAlmacen &);
#endif /* SOBRECARGAS_HPP */


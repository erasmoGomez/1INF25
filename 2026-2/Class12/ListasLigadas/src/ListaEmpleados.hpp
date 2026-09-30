/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaEmpleados.hpp
 * Author: Erasmo G. Montoya
 *
 * Created on April 28, 2026, 5:01 PM
 */

#ifndef LISTAEMPLEADOS_HPP
#define LISTAEMPLEADOS_HPP
#include "ListaGenerica.hpp"

void *lee_empleado(ifstream &);

int compara_empleado_nombre(const void *, const void *);

void imprime_empleado(void *, ofstream &);
#endif /* LISTAEMPLEADOS_HPP */

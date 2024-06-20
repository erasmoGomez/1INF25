/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NodoLista.hpp
 * Author: Erasmo G. Montoya
 *
 * Created on June 12, 2024, 7:35 AM
 */

#ifndef NODOLISTA_HPP
#define NODOLISTA_HPP
#include "Vehiculo.hpp"
#include "LVehiculos.hpp"
class NodoLista {
public:
    NodoLista();
    NodoLista(const NodoLista& orig);
    virtual ~NodoLista();
    friend class LVehiculos;
private:
    Vehiculo* unidad;
    NodoLista* sig;

};

#endif /* NODOLISTA_HPP */


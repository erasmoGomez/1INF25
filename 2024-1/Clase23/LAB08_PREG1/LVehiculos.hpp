/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LVehiculos.hpp
 * Author: Erasmo G. Montoya
 *
 * Created on June 12, 2024, 7:38 AM
 */

#ifndef LVEHICULOS_HPP
#define LVEHICULOS_HPP
#include "NodoLista.hpp"
#include "Utils.hpp"
using namespace std;
class LVehiculos {
public:
    LVehiculos();
    LVehiculos(const LVehiculos& orig);
    virtual ~LVehiculos();
    lee_inserta(char, ifstream&);
private:
    class NodoLista* lini;
    class NodoLista* lfin;
};

#endif /* LVEHICULOS_HPP */


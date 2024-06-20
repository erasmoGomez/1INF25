/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Vehiculo.hpp
 * Author: Erasmo G. Montoya
 *
 * Created on June 12, 2024, 7:25 AM
 */

#ifndef VEHICULO_HPP
#define VEHICULO_HPP
#include "NPedido.hpp"
#include "Utils.hpp"
using namespace std;
class Vehiculo {
public:
    Vehiculo();
    Vehiculo(const Vehiculo& orig);
    virtual ~Vehiculo();
    virtual void lee(ifstream&); //Metodo Polimorfico
private:
    int cliente;
    char* placa;
    double maxcarga;
    double actcarga;
    class NPedido* ped;
    
};

#endif /* VEHICULO_HPP */


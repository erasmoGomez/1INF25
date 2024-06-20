/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Camion.hpp
 * Author: Erasmo G. Montoya
 *
 * Created on June 12, 2024, 7:29 AM
 */

#ifndef CAMION_HPP
#define CAMION_HPP
#include "Vehiculo.hpp"
#include "Utils.hpp"
using namespace std;
class Camion : public Vehiculo {
public:
    Camion();
    Camion(const Camion& orig);
    virtual ~Camion();
    void lee(ifstream&);
private:
    int eje;
    int llantas;
};

#endif /* CAMION_HPP */


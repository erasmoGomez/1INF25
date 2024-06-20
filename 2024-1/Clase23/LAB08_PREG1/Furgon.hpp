/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Furgon.hpp
 * Author: Erasmo G. Montoya
 *
 * Created on June 12, 2024, 7:30 AM
 */

#ifndef FURGON_HPP
#define FURGON_HPP
#include "Vehiculo.hpp"
#include "Utils.hpp"
using namespace std;
class Furgon: public Vehiculo {
public:
    Furgon();
    Furgon(const Furgon& orig);
    virtual ~Furgon();
    void lee(ifstream&);
private:
    int filas;
    int puertas;
};

#endif /* FURGON_HPP */


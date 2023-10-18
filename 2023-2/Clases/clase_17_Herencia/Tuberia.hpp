/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tuberia.hpp
 * Author: ASUS
 *
 * Created on October 17, 2023, 9:49 AM
 */

#ifndef TUBERIA_HPP
#define TUBERIA_HPP
#include "Cilindro.hpp"
class Tuberia: public Cilindro{
public:
    Tuberia();
    Tuberia(const Tuberia& orig);
    virtual ~Tuberia();
    double Volumen();
    double Area();
private:
    double radioInterior;
};

#endif /* TUBERIA_HPP */


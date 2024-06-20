/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Flota.hpp
 * Author: Erasmo G. Montoya
 *
 * Created on June 12, 2024, 7:42 AM
 */

#ifndef FLOTA_HPP
#define FLOTA_HPP
#include "LVehiculos.hpp"
class Flota {
public:
    Flota();
    Flota(const Flota& orig);
    virtual ~Flota();
    void cargarflota();
private:
    class LVehiculos lista;
};

#endif /* FLOTA_HPP */


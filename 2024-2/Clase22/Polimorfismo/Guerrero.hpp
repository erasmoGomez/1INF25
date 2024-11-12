/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Guerrero.hpp
 * Author: Erasmo G. Montoya
 *
 * Created on October 28, 2024, 6:09 PM
 */

#ifndef GUERRERO_HPP
#define GUERRERO_HPP

#include "Personaje.hpp"


class Guerrero : public Personaje{
public:
    Guerrero();
    Guerrero(const Guerrero& orig);
    virtual ~Guerrero();
    void realizarAccion();
    void realizarAccionPura();
private:
    int vida;
};

#endif /* GUERRERO_HPP */


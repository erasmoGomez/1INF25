/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Mago.hpp
 * Author: hecto
 *
 * Created on May 14, 2025, 4:39 PM
 */

#ifndef MAGO_HPP
#define MAGO_HPP
#include "Heroe.hpp"
class Mago: public Heroe {
public:
    Mago();
    Mago(const Mago& orig);
    virtual ~Mago();
    void setMana(double mana);
    double getMana() const;
    //Sobrescribir el metodo mostrar_heroe
    void mostrar_heroe(ostream&) const;
private:
    double mana;
};

#endif /* MAGO_HPP */


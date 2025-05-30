/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Mago.hpp
 * Author: hecto
 *
 * Created on May 30, 2025, 5:20 AM
 */

#ifndef MAGO_HPP
#define MAGO_HPP
#include "Personaje.hpp"
class Mago : public Personaje {
public:
    Mago();
    Mago(const Mago& orig);
    virtual ~Mago();
    Mago(const char* nombre_in, int nivel_in, int poder_magico_in, int mana_in);
    void mostrar() const;
    void leer(ifstream&);
private:
    int poder_magico;
    int mana;
};

#endif /* MAGO_HPP */


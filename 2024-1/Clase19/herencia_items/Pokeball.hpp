/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Pokeball.hpp
 * Author: ASUS
 *
 * Created on May 23, 2024, 7:56 AM
 */

#ifndef POKEBALL_HPP
#define POKEBALL_HPP

#include "Item.hpp"

class Pokeball: public Item{
private:
    int valor;
public:
    Pokeball();
    void SetValor(int valor);
    int GetValor() const;
    void mostrar();
            
};

#endif /* POKEBALL_HPP */


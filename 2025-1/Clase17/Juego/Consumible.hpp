/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Consumible.hpp
 * Author: hecto
 *
 * Created on May 14, 2025, 5:40 PM
 */

#ifndef CONSUMIBLE_HPP
#define CONSUMIBLE_HPP
#include "Item.hpp"
class Consumible: public Item {
public:
    Consumible();
    Consumible(const Consumible& orig);
    virtual ~Consumible();
private:
    int modificador_hp;
};

#endif /* CONSUMIBLE_HPP */


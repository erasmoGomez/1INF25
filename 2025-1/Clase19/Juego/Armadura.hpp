/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Armadura.hpp
 * Author: hecto
 *
 * Created on May 14, 2025, 5:38 PM
 */

#ifndef ARMADURA_HPP
#define ARMADURA_HPP
#include "Item.hpp"
class Armadura: public Item {
public:
    Armadura();
    Armadura(const Armadura& orig);
    virtual ~Armadura();
    void leer(ifstream&);
private:
    int modificador_defensa;
};

#endif /* ARMADURA_HPP */


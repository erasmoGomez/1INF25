/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Consumable.hpp
 * Author: ASUS
 *
 * Created on October 18, 2023, 7:58 AM
 */

#ifndef CONSUMABLE_HPP
#define CONSUMABLE_HPP
#include "Item.hpp"

class Consumable : public Item {
public:
    Consumable();
    Consumable(const Consumable& orig);
    virtual ~Consumable();
    void muestra(ofstream &);
    void actualiza();
private:
    int hp;
};

#endif /* CONSUMABLE_HPP */


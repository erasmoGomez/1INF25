/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Armor.hpp
 * Author: ASUS
 *
 * Created on October 18, 2023, 7:54 AM
 */

#ifndef ARMOR_HPP
#define ARMOR_HPP
#include "Item.hpp"

class Armor : public Item {
public:
    Armor();
    Armor(const Armor& orig);
    virtual ~Armor();
    void muestra(ofstream &);
    void actualiza();
private:
    int def;
};

#endif /* ARMOR_HPP */


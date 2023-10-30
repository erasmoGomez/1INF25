/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Weapon.hpp
 * Author: ASUS
 *
 * Created on October 18, 2023, 7:57 AM
 */

#ifndef WEAPON_HPP
#define WEAPON_HPP
#include "Item.hpp"

class Weapon : public Item {
public:
    Weapon();
    Weapon(const Weapon& orig);
    virtual ~Weapon();
    void actualiza();
    void muestra(ofstream &);
private:
    int att;
};

#endif /* WEAPON_HPP */


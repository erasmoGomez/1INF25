/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Consumible.hpp
 * Author: Erasmo G. Montoya
 *
 * Created on October 22, 2024, 6:12 PM
 */

#ifndef CONSUMIBLE_HPP
#define CONSUMIBLE_HPP
#include "Utils.hpp"
#include "Item.hpp"
using namespace std;

class Consumible: public Item {
public:
    Consumible();
    Consumible(const Consumible& orig);
    virtual ~Consumible();
    void SetModificador_hp(int modificador_hp);
    int GetModificador_hp() const;
    void leer(ifstream&);
private:
    int modificador_hp;
};

#endif /* CONSUMIBLE_HPP */


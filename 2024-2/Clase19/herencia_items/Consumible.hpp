/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Consumible.hpp
 * Author: ASUS
 *
 * Created on May 23, 2024, 8:21 AM
 */

#ifndef CONSUMIBLE_HPP
#define CONSUMIBLE_HPP
#include "Item.hpp"
class Consumible: public Item{
private:
    int valor;
public:
    Consumible();
    void SetValor(int valor);
    int GetValor() const;
     void mostrar();  
};


#endif /* CONSUMIBLE_HPP */


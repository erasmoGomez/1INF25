/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   consumable.hpp
 * Author: erasmog
 *
 * Created on June 14, 2023, 8:11 AM
 */

#ifndef CONSUMABLE_HPP
#define CONSUMABLE_HPP
#include "item.hpp"

class Consumable : public Item {
private:
    int variacion;
    int caracteristica;
public:
    Consumable();
    Consumable(int, char*, char*, int, int=1);
    void SetCaracteristica(int caracteristica);
    int GetCaracteristica() const;
    void SetVariacion(int variacion);
    int GetVariacion() const;
    void load_consumable(int, const char*, const char*, int, int=1);
    void print_consumable();
};

#endif /* CONSUMABLE_HPP */


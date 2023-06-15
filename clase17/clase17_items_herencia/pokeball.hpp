/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   pokeball.hpp
 * Author: erasmog
 *
 * Created on June 14, 2023, 7:38 AM
 */

#ifndef POKEBALL_HPP
#define POKEBALL_HPP

#include "item.hpp"

class Pokeball : public Item {
private:
    double catch_ratio;
public:
    Pokeball();
    Pokeball(int, const char*, const char*, double);
    void SetCatch_ratio(double catch_ratio);
    double GetCatch_ratio() const;
    void load_pokeball(int, const char*, const char*, double);
    void print_pokeball();
};

#endif /* POKEBALL_HPP */


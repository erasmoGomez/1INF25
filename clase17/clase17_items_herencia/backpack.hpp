/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   backpack.hpp
 * Author: erasmog
 *
 * Created on June 14, 2023, 8:42 AM
 */

#ifndef BACKPACK_HPP
#define BACKPACK_HPP
//#include "functions.hpp"
#include "item.hpp"
#include "pokeball.hpp"
#include "consumable.hpp"

class Backpack{
private:
    Pokeball pokeballs[100];
    Consumable consumables[100];
public:
    Backpack();
    void cargar_pokeballs(int);
    void cargar_consumables(int);
    void mostrar_pokeballs();
    void mostrar_pokeballs_pos(int);
    void mostrar_consumables();
    void mostrar_consumables_pos(int);
    void load_backpack();
};


#endif /* BACKPACK_HPP */


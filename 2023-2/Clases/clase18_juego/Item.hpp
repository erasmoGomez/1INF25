/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Item.hpp
 * Author: ASUS
 *
 * Created on October 18, 2023, 7:47 AM
 */

#ifndef ITEM_HPP
#define ITEM_HPP

class Item {
public:
    Item();
    Item(const Item& orig);
    virtual ~Item();
private:
    int code;
    char *name;
    char *description;
    int codigo_hero;
};

#endif /* ITEM_HPP */


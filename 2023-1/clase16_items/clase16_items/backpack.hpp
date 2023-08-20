/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   backpack.hpp
 * Author: erasmog
 *
 * Created on June 7, 2023, 7:19 AM
 */

#ifndef BACKPACK_HPP
#define BACKPACK_HPP
#include "item.hpp"

class Backpack{
private:
    int ID;
    char * name;
    Item items[100];
    int limit;
public:
    Backpack();
    void SetLimit(int limit);
    int GetLimit() const;
    void SetItem(Item &, int);
    Item * GetItems() ;
    Item& GetItem(int);
    void SetName(const char* name);
    void GetName(char *) const;
    void SetID(int ID);
    int GetID() const;
    void operator+=(class Item &);
    
};

void operator>>(ifstream &, class Backpack&); //arch>>item
void operator<<(ofstream &, class Backpack&); 
#endif /* BACKPACK_HPP */


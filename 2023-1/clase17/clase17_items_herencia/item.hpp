/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   item.hpp
 * Author: erasmog
 *
 * Created on June 7, 2023, 7:16 AM
 */

#ifndef ITEM_HPP
#define ITEM_HPP
#include <fstream>
using namespace std;

class Item{
protected:
    int ID;
private:
    char * name;
    char * description;
public:
    Item();
    Item(int, const char *, const char * = "None");
    void SetDescription(const char* );
    void GetDescription(char *) const;
    void SetName(const char* );
    void GetName(char *) const;
    void SetID(int );
    int GetID() const;
};

void operator>>(ifstream &, class Item&); //arch>>item
void operator<<(ofstream &, class Item&); 
//ifstream & operator>>(ifstream &, class Item&); // arch>>item>>item2>>item3

#endif /* ITEM_HPP */


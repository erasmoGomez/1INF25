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
using namespace std;

class Item{
private:
    int ID;
    char * name;
    char * description;
    int type;
public:
    Item();
    Item(int, const char *, const char * = "None", int=1);
    void SetType(int );
    int GetType() const;
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


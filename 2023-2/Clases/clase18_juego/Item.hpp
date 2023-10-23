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
#include "utils.hpp"
using namespace std;

class Item {
public:
    Item();
    Item(const Item& orig);
    virtual ~Item();
    void SetValue(int value);
    int GetValue() const;
    void SetCodigo_hero(int codigo_hero);
    int GetCodigo_hero() const;
    void SetDescription(const char* description);
    void GetDescription(char *description) const;
    void SetName(const char* name);
    void GetName(char *name) const;
    void SetCode(int code);
    int GetCode() const;
    void mostrar_item(ofstream &) const;
private:
    int code;
    char *name;
    char *description;
    int codigo_hero;
    int value;
};

void operator>>(ifstream&, class Item&);
void operator<<(ofstream&, const class Item&);

#endif /* ITEM_HPP */


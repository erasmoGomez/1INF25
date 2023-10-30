/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Hero.hpp
 * Author: ASUS
 *
 * Created on October 18, 2023, 7:43 AM
 */

#ifndef HERO_HPP
#define HERO_HPP
#include "utils.hpp"
#include "Item.hpp"
using namespace std;

class Hero {
public:
    Hero();
    Hero(const Hero& orig);
    virtual ~Hero();
    void SetHp(int hp);
    int GetHp() const;
    void SetAtt(int att);
    int GetAtt() const;
    void SetPosy(int posy);
    int GetPosy() const;
    void SetPosx(int posx);
    int GetPosx() const;
    void SetName(const char* name);
    void GetName(char* name) const;
    void SetCode(int code);
    int GetCode() const;
    void mostrar_hero(ofstream &) const;
    void leer_items(ifstream *);
    void operator +=(const class Item &);
    void operator +=(class Item *i);
private:
    int code;
    char* name;
    int posx;
    int posy;
    int att;
    int hp;
    class Item *mochila;
    int n_items;
};

void operator>>(ifstream&, class Hero&);
void operator<<(ofstream&, const class Hero&);
#endif /* HERO_HPP */


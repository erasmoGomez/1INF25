/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   hero.hpp
 * Author: erasmog
 *
 * Created on May 31, 2023, 8:56 AM
 */

#ifndef HERO_HPP
#define HERO_HPP
#include "functions.hpp"

class Hero {
private:
    char * nombre;
    char tileChar;
    int hp;
    int posX;
    int posY;

public:
    Hero();
    Hero(const char *, char='H', int = 100, int = MAX_ROWS / 2, int = MAX_COLUMNS / 2);
    Hero(Hero &h);      //copy constructor
    virtual ~Hero();
    void SetHp(int);
    void SetPosX(int);
    void SetPosY(int);
    void SetNombre(const char*);
    void SetTileChar(char);
    int GetHp() const;
    int GetPosX() const;
    int GetPosY() const;
    void GetNombre(char*) const;
    char GetTileChar() const;
    void move(int, int);
};

void operator<<(ofstream &, const class Hero &);


#endif /* HERO_HPP */


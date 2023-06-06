/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   hero.hpp
 * Author: erasmog
 *
 * Created on June 6, 2023, 7:56 AM
 */

#ifndef HERO_HPP
#define HERO_HPP
#include "functions.hpp"
class Hero{
private:
    char* nombre;
    char tileChar;
    int hp;
    int posX;
    int posY;
public:
    Hero();
    Hero(const char *, char= 'X', int = 100, int = MAX_ROWS/2, int = MAX_COLUMNS/2);
    virtual ~Hero();
    void SetPosY(int);
    int GetPosY() const;
    void SetPosX(int);
    int GetPosX() const;
    void SetHp(int);
    int GetHp() const;
    void SetTileChar(char);
    char GetTileChar() const;
    void SetNombre(const char*);
    void GetNombre(char *) const;
    void Move(int, int);
    void Move(int, char);
    
};

void operator<<(ofstream &, const class Hero&);


#endif /* HERO_HPP */


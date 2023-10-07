/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   hero.hpp
 * Author: ASUS
 *
 * Created on September 27, 2023, 7:58 AM
 */

#ifndef HERO_HPP
#define HERO_HPP
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;

class Hero{
private:
    char *name;
    int hp;
    double attack;
    int posx;
    int posy;
public:
    Hero();
    virtual ~Hero();
    void SetPosy(int posy);
    int GetPosy() const;
    void SetPosx(int posx);
    int GetPosx() const;
    void SetAttack(double attack);
    double GetAttack() const;
    void SetHp(int hp);
    int GetHp() const;
    void SetName(const char* name);
    void GetName(char*) const;
    void Display();
    void operator++(void);
    void operator++(int);
    void operator--(void);
    void operator--(int);
};

void operator <<(ofstream&, const class Hero&);

#endif /* HERO_HPP */


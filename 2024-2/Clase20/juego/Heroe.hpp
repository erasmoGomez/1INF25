/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Heroe.hpp
 * Author: ASUS
 *
 * Created on May 7, 2024, 9:46 AM
 */

#ifndef HEROE_HPP
#define HEROE_HPP
#include "Utils.hpp"
using namespace std;
class Heroe{
private:
    char *nombre;
    int hp;
    double mana;
    int posx;
    int posy;
public:
    Heroe();
    void leer(ifstream &);
    void mostrar();
    void setPosy(int posy);
    int getPosy() const;
    void setPosx(int posx);
    int getPosx() const;
    void setMana(double mana);
    double getMana() const;
    void setHp(int hp);
    int getHp() const;
    void setNombre(const char*);
    void getNombre(char*) const;
    
    //heroe++ W
    void operator++(int);
    //++heroe S
    void operator++();
    //heroe-- D
    void operator--(int);
    //--heroe A
    void operator--();
    
};

void operator>>(ifstream&, Heroe&);

//void operator<<(ofstream&, Heroe&);
#endif /* HEROE_HPP */


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
#include "Mochila.hpp"
using namespace std;
class Heroe{
private:
    char *nombre;
    int hp;
    double mana;
    int posx;
    int posy;
    int ataque;
    int defensa;
    Mochila mochila;
public:
    Heroe();
    void leer(ifstream &);
    void mostrar() const;
    void mostrar(ofstream&) const;
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
    void agregar_mochila(ifstream&, char*);
    //heroe++ W
    void operator++(int);
    //++heroe S
    void operator++();
    //heroe-- D
    void operator--(int);
    //--heroe A
    void operator--();
    
    bool operator > (const Heroe &);
    void operator = (const Heroe &);
    
    void equipar(const char*, const char*);
    void equipar(int , const char*);
    void equipar_item(const char*, int);
    void setDefensa(int defensa);
    int getDefensa() const;
    void setAtaque(int ataque);
    int getAtaque() const; // 0: vida, 1: ataque, 2: defensa
};

void operator>>(ifstream&, Heroe&);

void operator<<(ofstream&, const Heroe&);

void operator<<(ostream&, const Heroe&);
#endif /* HEROE_HPP */


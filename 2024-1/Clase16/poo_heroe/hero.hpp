/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   hero.hpp
 * Author: ASUS
 *
 * Created on April 30, 2024, 9:08 PM
 */

#ifndef HERO_HPP
#define HERO_HPP

class Heroe{
private:
    char * nombre;
    int hp;
    double mana;
    int posx;
    int posy;      
public:
    void crear_heroe();
    void mover(int, int, double);
    void curar(int);
    void mostrar();
};

#endif /* HERO_HPP */


/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   heroe.hpp
 * Author: erasmog
 *
 * Created on May 31, 2023, 8:56 AM
 */

#ifndef HEROE_HPP
#define HEROE_HPP

class Heroe{
private:
    char * nombre;
    int mana;
    int hp;
    
public:
    void caminar();
    void set_hp(int);
};

#endif /* HEROE_HPP */


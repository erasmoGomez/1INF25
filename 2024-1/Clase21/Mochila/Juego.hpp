/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Juego.hpp
 * Author: Erasmo G. Montoya
 *
 * Created on May 27, 2024, 5:58 PM
 */

#ifndef JUEGO_HPP
#define JUEGO_HPP
#include "Heroe.hpp"
class Juego {
public:
    Juego();
    Juego(const Juego& orig);
    virtual ~Juego();
    void carga_items();
    void jugar();
    
private:
    Heroe heroes[10];
};

#endif /* JUEGO_HPP */


/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Heroe.hpp
 * Author: Erasmo G. Montoya
 *
 * Created on May 27, 2024, 5:36 PM
 */

#ifndef HEROE_HPP
#define HEROE_HPP
#include "Utils.hpp"
#include "Mochila.hpp"
using namespace std;
class Heroe{
private:
    char *nombre;
    int vida;
    int ataque;
    int defensa;
    Mochila mochila;
public:
    Heroe();
    void agregar_mochila(ifstream &, char*);
    void setDefensa(int defensa);
    int getDefensa() const;
    void setAtaque(int ataque);
    int getAtaque() const;
    void setVida(int vida);
    int getVida() const;
    void setNombre(const char* nombre);
    void getNombre(char*) const;
    void equipar(const char*, const char*);
//    void equipar(Consumible&);
//    void equipar(Armadura&);
//    void equipar(Arma&);
   
};


#endif /* HEROE_HPP */


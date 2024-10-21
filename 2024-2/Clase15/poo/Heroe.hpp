/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Heroe.hpp
 * Author: Erasmo G. Montoya
 *
 * Created on October 7, 2024, 5:37 PM
 */

#ifndef HEROE_HPP
#define HEROE_HPP
#include "utils.hpp"

class Heroe {
private:
    char* nombre;
    int vida;
    double mana;
    int posX;
    int posY;
public:
    Heroe(); //Constructor por Defecto
    Heroe(const char*, int); //Constructor por parametros
    //Heroe(int, int, int, double);
    Heroe(const Heroe&); //Constructor Copia
    void crear();
    void mostrar();
    void mover(int, int);
    void curar(int);
    void setPosY(int posY);
    int getPosY() const;
    void setPosX(int posX);
    int getPosX() const;
    void setMana(double mana);
    double getMana() const;
    void setVida(int vida);
    int getVida() const;
    void setNombre(const char* nombre);
    void getNombre(char* nombre) const;
};

#endif /* HEROE_HPP */


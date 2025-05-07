/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Heroe.hpp
 * Author: hecto
 *
 * Created on May 6, 2025, 5:55 PM
 */

#ifndef HEROE_HPP
#define HEROE_HPP
#include "utils.hpp"
class Heroe {
public:
    Heroe(); //Constructor por Defecto
    Heroe(int, double, double); //Constructor con Parametros
//    Heroe::Heroe(const Heroe& orig);
//    Heroe::~Heroe();
    
    void cargar_info(ifstream&);
    void mostrar_info(ofstream&);
    void setPosY(int posY);
    int getPosY() const;
    void setPosX(int posX);
    int getPosX() const;
    void setDefensa(double defensa);
    double getDefensa() const;
    void setFuerza(double fuerza);
    double getFuerza() const;
    void setHp(int hp);
    int getHp() const;
    
    void setNombre(const char* nombre);
    void getNombre(char* nombre) const;
    void setId(const char* id);
    void getId(char* id) const;
    //Getters y Setters
private:
    char* id;
    char* nombre;
    int hp;
    double fuerza;
    double defensa;
    int posX;
    int posY;
};

#endif /* HEROE_HPP */


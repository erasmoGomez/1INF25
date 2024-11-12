/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Personaje.hpp
 * Author: Erasmo G. Montoya
 *
 * Created on October 28, 2024, 5:39 PM
 */

#ifndef PERSONAJE_HPP
#define PERSONAJE_HPP
#include "Utils.hpp"
class Personaje{
public:
    Personaje();
    Personaje(const Personaje& orig);
    void SetPoder(int poder);
    int GetPoder() const;
    void SetNombre(char*);
    void GetNombre (char*) const;
    void operator = (const Personaje&);
    virtual void realizarAccion();
    virtual void realizarAccionPura() = 0; //Funcion Pura
private:
    int poder;
    char* nombre; //Si se trabaja con memoria, se requiere la sobrecarga del operador =
};

#endif /* PERSONAJE_HPP */


/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Espacio.hpp
 * Author: hecto
 *
 * Created on May 28, 2025, 4:37 PM
 */

#ifndef ESPACIO_HPP
#define ESPACIO_HPP
#include "Utils.hpp"

class Espacio {
public:
    Espacio();
    Espacio(const Espacio& orig);
    virtual ~Espacio();
    void SetPosY(int posY);
    int GetPosY() const;
    void SetPosX(int posX);
    int GetPosX() const;
    void SetContenido(char contenido);
    char GetContenido() const;
    
    void mostrar(ofstream&) const;
private:
    char contenido;
    int posX;
    int posY;
};

void operator<<(ofstream&, const Espacio&);
#endif /* ESPACIO_HPP */


/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Espacio.hpp
 * Author: Erasmo G. Montoya
 *
 * Created on May 23, 2024, 10:20 PM
 */

#ifndef ESPACIO_HPP
#define ESPACIO_HPP

#include "Utils.hpp"
using namespace std;

class Espacio {
private:
    int posx;
    int posy;
    char contenido;
public:
    char getContenido() const;

    void setContenido(char contenido);

    int getPosx() const;

    void setPosx(int posx);

    int getPosy() const;

    void setPosy(int posy);

    Espacio();

    void muestra(ofstream&);
};

#endif /* ESPACIO_HPP */


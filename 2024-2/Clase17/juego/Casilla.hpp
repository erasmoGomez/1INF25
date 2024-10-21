/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Casilla.hpp
 * Author: ASUS
 *
 * Created on May 7, 2024, 9:39 AM
 */

#ifndef CASILLA_HPP
#define CASILLA_HPP
#include "Utils.hpp"
using namespace std;
class Casilla{
private:
    char elemento;
    int x;
    int y;
public:
    Casilla();
    Casilla(int, int, char);
    void leer(ifstream &);
    void mostrar(ostream &);
    void setY(int y);
    int getY() const;
    void setX(int x);
    int getX() const;
    void setElemento(char elemento);
    char getElemento() const;
};
void operator>>(ifstream&, Casilla&);
void operator<<(ostream&, Casilla);

#endif /* CASILLA_HPP */


/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Casilla.hpp
 * Author: hecto
 *
 * Created on May 7, 2025, 4:55 PM
 */

#ifndef CASILLA_HPP
#define CASILLA_HPP
#include "utils.hpp"
class Casilla {
public:
    Casilla();
    Casilla(bool);
    Casilla(const Casilla& orig);
    virtual ~Casilla();
    void mostrar_info(ostream&) const;
    void setSprite(char sprite);
    char getSprite() const;
    void setContieneHeroe(bool contieneHeroe);
    bool isContieneHeroe() const;
    void setTransitable(bool transitable);
    bool isTransitable() const;
private:
    bool transitable;
    bool contieneHeroe;
    char sprite;
};

void operator << (ostream&, class Casilla&);
#endif /* CASILLA_HPP */


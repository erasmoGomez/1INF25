/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Arma.hpp
 * Author: hecto
 *
 * Created on May 14, 2025, 5:39 PM
 */

#ifndef ARMA_HPP
#define ARMA_HPP
#include "Item.hpp"
class Arma: public Item {
public:
    Arma();
    Arma(const Arma& orig);
    virtual ~Arma();
    void setModificador_poder(int modificador_poder);
    int getModificador_poder() const;
    void leer(ifstream&);
    void mostrar(ostream&) const;
    int get_valor();
private:
    int modificador_poder;
};

#endif /* ARMA_HPP */


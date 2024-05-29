/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Arma.hpp
 * Author: Erasmo G. Montoya
 *
 * Created on May 27, 2024, 5:42 PM
 */

#ifndef ARMA_HPP
#define ARMA_HPP
#include "Item.hpp"
class Arma: public Item {
public:
    Arma();
    Arma(const Arma& orig);
    virtual ~Arma();
    void SetModificador_att(int modificador_att);
    int GetModificador_att() const;
    void leer(ifstream &);
private:
    int modificador_att;
};

#endif /* ARMA_HPP */


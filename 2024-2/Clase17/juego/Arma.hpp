/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Arma.hpp
 * Author: Erasmo G. Montoya
 *
 * Created on October 22, 2024, 6:12 PM
 */

#ifndef ARMA_HPP
#define ARMA_HPP
#include "Utils.hpp"
#include "Item.hpp"
using namespace std;
class Arma: public Item {
public:
    Arma();
    Arma(const Arma& orig);
    virtual ~Arma();
    void SetModificador_ataque(int modificador_ataque);
    int GetModificador_ataque() const;
    void leer(ifstream&);
private:
    int modificador_ataque;
};

#endif /* ARMA_HPP */


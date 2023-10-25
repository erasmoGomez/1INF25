/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Derivada.hpp
 * Author: ASUS
 *
 * Created on October 24, 2023, 9:29 AM
 */

#ifndef DERIVADA_HPP
#define DERIVADA_HPP
#include "Base.hpp"
class Derivada : public Base {
public:
    Derivada();
    Derivada(const Derivada& orig);
    virtual ~Derivada();
    void SetD(int d);
    int GetD() const;
    void mostrar();
private:
    int d;
};

#endif /* DERIVADA_HPP */


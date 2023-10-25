/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Derivada2.hpp
 * Author: ASUS
 *
 * Created on October 24, 2023, 9:36 AM
 */

#ifndef DERIVADA2_HPP
#define DERIVADA2_HPP
#include "Base.hpp"
class Derivada2 : public Base {
public:
    Derivada2();
    Derivada2(const Derivada2& orig);
    virtual ~Derivada2();
    void SetD2(int d2);
    int GetD2() const;
    void mostrar();
private:
    int d2;
};

#endif /* DERIVADA2_HPP */


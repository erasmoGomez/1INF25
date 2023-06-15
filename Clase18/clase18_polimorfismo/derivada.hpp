/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   derivada.hpp
 * Author: erasmog
 *
 * Created on June 14, 2023, 10:12 PM
 */

#ifndef DERIVADA_HPP
#define DERIVADA_HPP

#include "base.hpp"

class Derivada : public Base {
private:
    int d;
public:
    void SetD(int d);
    int GetD() const;
    void imprime();
};

#endif /* DERIVADA_HPP */


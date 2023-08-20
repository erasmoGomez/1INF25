/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   derivada2.hpp
 * Author: erasmog
 *
 * Created on June 14, 2023, 10:23 PM
 */

#ifndef DERIVADA2_HPP
#define DERIVADA2_HPP

#include "base.hpp"
class Derivada2 : public Base {
private:
    int dd;
public:
    void SetDd(int dd);
    int GetDd() const;
    void imprime();
};

#endif /* DERIVADA2_HPP */


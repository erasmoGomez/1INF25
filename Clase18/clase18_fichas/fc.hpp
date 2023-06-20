/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   fc.hpp
 * Author: erasmog
 *
 * Created on June 20, 2023, 7:10 AM
 */

#ifndef FC_HPP
#define FC_HPP
#include <fstream>
#include "ficha.hpp"
using namespace std;

class Fc : public Ficha {
public:
    void imprime(ofstream &);
    void mover(char, int);
};


#endif /* FC_HPP */


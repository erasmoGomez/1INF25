/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   fa.hpp
 * Author: erasmog
 *
 * Created on June 14, 2023, 10:59 PM
 */

#ifndef FA_HPP
#define FA_HPP
#include <fstream>
#include "ficha.hpp"
using namespace std;

class Fa : public Ficha {
public:
    void imprime(ofstream &);
    //void mover(char, int);
};

#endif /* FA_HPP */


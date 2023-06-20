/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   fb.hpp
 * Author: erasmog
 *
 * Created on June 20, 2023, 7:07 AM
 */

#ifndef FB_HPP
#define FB_HPP
#include <fstream>
#include "ficha.hpp"
using namespace std;
class Fb : public Ficha {
public:
    void imprime(ofstream &);
    void mover(char, int);
};

#endif /* FB_HPP */


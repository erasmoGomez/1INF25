/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RedSocial.hpp
 * Author: Erasmo G. Montoya
 *
 * Created on November 12, 2024, 6:05 PM
 */

#ifndef REDSOCIAL_HPP
#define REDSOCIAL_HPP
#include <iostream>
#include <vector>
#include <map>
#include "persona.hpp"
using namespace std;
class RedSocial {
public:
    RedSocial();
    RedSocial(const RedSocial& orig);
    virtual ~RedSocial();
    void agregar_relacion(const Persona&, const Persona&);
    void imprimir();
private:
    map<Persona,vector<Persona>> adyacencias;
};
//Matrix de ADYACENCIA
//    P1   P2   P3   P4
//P1   0   1    1    1 -> P2, P3, P4
//P2   0   0    1    0 -> P3
//P3   1   0    0    1 -> P1, P4
//P4   0   1    0    0 -> P2
//KEY                     VALUE  
#endif /* REDSOCIAL_HPP */


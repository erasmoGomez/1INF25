/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RedSocial.hpp
 * Author: hecto
 *
 * Created on June 18, 2025, 5:01 PM
 */

#ifndef REDSOCIAL_HPP
#define REDSOCIAL_HPP
#include "Utils.hpp"
#include "Persona.hpp"
class RedSocial {
public:
    RedSocial();
    RedSocial(const RedSocial& orig);
    virtual ~RedSocial();
    void agregar_arista(const Persona&, const Persona&);
    void imprimir();
private:
    map<class Persona, vector<class Persona>> adyacencias;
};

#endif /* REDSOCIAL_HPP */


/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Mochila.hpp
 * Author: Erasmo G. Montoya
 *
 * Created on May 27, 2024, 5:37 PM
 */

#ifndef MOCHILA_HPP
#define MOCHILA_HPP
#include "Consumible.hpp"
#include "Arma.hpp"
#include "Armadura.hpp"
#include "Utils.hpp"
using namespace std;
class Mochila {
public:
    
    Mochila();
    Mochila(const Mochila& orig);
    virtual ~Mochila();
    void SetN_armaduras(int n_armaduras);
    int GetN_armaduras() const;
    void SetN_armas(int n_armas);
    int GetN_armas() const;
    void SetN_consumibles(int n_consumibles);
    int GetN_consumibles() const;
    void agregar_item(ifstream &, char*);
    void equipar(const char* );
    int buscar_consumible(const char*);
    int buscar_armadura(const char*);
    int buscar_arma(const char*);
private:
    Consumible bolsillo_consumibles[10];
    int n_consumibles;
    Arma bolsillo_armas[10];
    int n_armas;
    Armadura bolsillo_armaduras[10];
    int n_armaduras;
};

#endif /* MOCHILA_HPP */


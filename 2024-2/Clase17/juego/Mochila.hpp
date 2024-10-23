/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Mochila.hpp
 * Author: Erasmo G. Montoya
 *
 * Created on October 22, 2024, 5:45 PM
 */

#ifndef MOCHILA_HPP
#define MOCHILA_HPP
#include "Utils.hpp"
#include "Consumible.hpp"
#include "Armadura.hpp"
#include "Arma.hpp"

using namespace std;
class Mochila {
public:
    Mochila();
    Mochila(const Mochila& orig);
    virtual ~Mochila();
    void SetN_armas(int n_armas);
    int GetN_armas() const;
    void SetN_armaduras(int n_armaduras);
    int GetN_armaduras() const;
    void SetN_consumibles(int n_consumibles);
    int GetN_consumibles() const;
    void agregar_item(ifstream& input, char*);
    void mostrar(ofstream&);
private:
    Consumible bolsillo_consumibles[15];
    int n_consumibles;
    Armadura bolsillo_armaduras[15];
    int n_armaduras;
    Arma bolsillo_armas[15];
    int n_armas;
};

#endif /* MOCHILA_HPP */


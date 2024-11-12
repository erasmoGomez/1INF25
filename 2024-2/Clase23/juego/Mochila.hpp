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
    void agregar_item(ifstream& , char*);
    void cargar_items(ifstream& , char* );
    void mostrar();
    int buscar_consumible(const char*);
    int buscar_consumible(int);
    int buscar_arma(const char*);
    int buscar_arma(int);
    int buscar_armadura(const char*);
    int buscar_armadura(int);
    void SetN_items(int n_items);
    int GetN_items() const;
    void asignar_memoria(char *);
    void mostrar_items();
    int buscar_item(const char*);
private:
    Consumible bolsillo_consumibles[15]{};
    int n_consumibles;
    Armadura bolsillo_armaduras[15]{};
    int n_armaduras;
    Arma bolsillo_armas[15]{};
    int n_armas;
    
    Item *items[45];
    int n_items;
};

#endif /* MOCHILA_HPP */


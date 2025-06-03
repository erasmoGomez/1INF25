/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Inventario.hpp
 * Author: hecto
 *
 * Created on May 27, 2025, 5:36 PM
 */

#ifndef INVENTARIO_HPP
#define INVENTARIO_HPP
#include "utils.hpp"
#include "Consumible.hpp"
#include "Armadura.hpp"
#include "Arma.hpp"

class Inventario {
public:
    Inventario();
    Inventario(const Inventario& orig);
    virtual ~Inventario();
    void SetN_armas(int n_armas);
    int GetN_armas() const;
    void SetN_armaduras(int n_armaduras);
    int GetN_armaduras() const;
    void SetN_consumibles(int n_consumibles);
    int GetN_consumibles() const;
    
    void cargar_items(ifstream &, char*);
    void mostrar_items(ostream&) const;
    
    int equipar_consumible(const char*);
    int equipar_armadura(const char*);
    int equipar_arma(const char*);
    
    void asignar_memoria(char*);
    int buscar_item(const char*);
private:
    Consumible ventana_consumibles[15]{};
    Armadura ventana_armaduras[15]{};
    Arma ventana_armas[15]{};
    int n_consumibles;
    int n_armaduras;
    int n_armas;
    
    //Puntero a la clase base
    Item* items[45]{};
    int n_items;
};

#endif /* INVENTARIO_HPP */


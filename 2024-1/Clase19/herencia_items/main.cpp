/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Erasmo G. Montoya
 *
 * Created on May 22, 2024, 7:37 AM
 */

#include "Item.hpp"
#include "Pokeball.hpp"
#include "Consumible.hpp"
using namespace std;
/*
 * 
 */
int main(int argc, char** argv) {
    Item i;
    i.SetNombre("Item 1");
    i.SetDescripcion("Es un item chevere");
    i.mostrar();
    
    Pokeball p;
    p.SetNombre("Master Ball");
    p.SetDescripcion("Es una master ball");
    p.SetValor(100);
    p.mostrar();
    
    Consumible c;
    c.SetNombre("Healing Potion");
    c.SetDescripcion("Es una pocion de curacion");
    c.SetValor(200);
    c.mostrar();
    
    return 0;
}


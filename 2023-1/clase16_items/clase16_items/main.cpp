/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: erasmog
 *
 * Created on June 7, 2023, 7:08 AM
 */

#include "functions.hpp"
#include "item.hpp"
#include "backpack.hpp"
/*
 * 
 */
int main(int argc, char** argv) {
//    Item i;
//    ifstream input("items.csv", ios::in);
    ofstream output("reporte.txt",ios::out);
//    input>>i;
//    output<<i;
    Item items[120];
    int n_items = 0;
    load_items(items,n_items, "items.csv");
    
    Backpack b;
    b+=items[0];
    output<<"Dato en la mochila N: "<<b.GetLimit()<<endl; // El atributo limite se modifica en cada insercion
    b+=items[1];
    output<<"Dato en la mochila N: "<<b.GetLimit()<<endl;
    b+=items[2];
    output<<"Dato en la mochila N: "<<b.GetLimit()<<endl;
    output<<"Item en la mochila"<<endl;
    output<<b.GetItem(b.GetLimit()); // Fijese q este limite pasa lo esperado
    output<<b.GetItem(b.GetLimit() - 1); // Para acceder al valor esperado
//    Backpack backpacks[120];
//    load_backpacks(backpacks, items, n_items, "backpack.csv");
    
    return 0;
}


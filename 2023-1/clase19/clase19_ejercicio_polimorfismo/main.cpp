/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: erasmog
 *
 * Created on June 20, 2023, 7:38 PM
 */

#include "farmacia.hpp"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Farmacia pedidos;
    pedidos.leer_recetas();
    pedidos.imprime_recetas();
    return 0;
}


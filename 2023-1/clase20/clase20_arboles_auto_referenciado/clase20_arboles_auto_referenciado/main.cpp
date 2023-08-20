/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: erasmog
 *
 * Created on June 27, 2023, 6:17 AM
 */

#include <iostream> 
#include <iomanip> 
using namespace std; 
#include "arbol.hpp"

int main(int argc, char** argv) {
    class Arbol arbol;
    arbol.crear("personalLL.csv");
    //arbol.recorrer_en_pre_orden();
    arbol.recorrer_en_orden();
    class Persona p;
    p = arbol.buscar(20082060);
    if (p.GetDni() != -1)
        cout << "Dato buscado: " << p << endl;
    else cout << "NO se encontro" << endl;
    return 0;
}


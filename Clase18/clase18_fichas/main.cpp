/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: erasmog
 *
 * Created on June 14, 2023, 10:45 PM
 */

#include "ficha.hpp"
#include "fa.hpp"

/*
 * 
 */
int main(int argc, char** argv) {
    Fa f;
    f.asigna("F1", 5, 10);
    ofstream arch("salida.txt", ios::out);
    f.imprime(arch);
    
    return 0;
}


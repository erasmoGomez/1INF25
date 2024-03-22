/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Erasmo G. Montoya
 *
 * Created on March 20, 2024, 7:59 AM
 */

#include "Sobrecargas.hpp"
#include "Functions.hpp"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Persona p;
    p.dni = 12345321;
    strcpy(p.nombre,"Erasmo");
    p.talla = 1.67;
    add_headers();
    cout<<p;
    return 0;
}


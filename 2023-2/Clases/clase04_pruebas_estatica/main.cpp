/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Erasmo G. Montoya
 *
 * Created on August 23, 2023, 7:47 AM
 */
#include <iostream>
#include <iomanip>
#include "Persona.hpp"
#include "Sobrecargas.hpp"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    struct Persona persona1{123456, "Erasmo Gomez", 1.5};
    struct Persona persona2{654321, "Cyndi Alaarcon", 1.5};
    struct Persona persona3{111111, "Xtian Juarez", 1.5};
    struct Persona persona4{6666666, "David Huingo", 1.5};

    persona1 *= 1.2;
    cout.precision(2);
    cout<<persona1.sueldo;
    return 0;
}


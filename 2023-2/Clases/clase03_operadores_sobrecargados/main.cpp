/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Erasmo G. Montoya
 *
 * Created on 22 de agosto de 2023, 07:43 AM
 */

#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
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
    fstream output ("salida.txt", ios::out);
    persona1 *= 1.2;
    cout.precision(2);
    cout<<persona1<<"Continuo"<<endl;
    
    persona3 = persona1 + persona2;
    cout<<persona3;
    //output<<persona1;
    //cout<<fixed<<persona2<<persona1;
    
    return 0;
}


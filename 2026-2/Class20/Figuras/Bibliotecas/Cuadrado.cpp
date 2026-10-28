//
// Created by erasmo on 6/2/26.
//

#include "Cuadrado.hpp"

#include <iostream>
#include <ostream>
using namespace std;

void Cuadrado::area() {
    cout<<"Area del Cuadrado"<<endl;
}

void Cuadrado::leer() {
    Figura::leer();
    cout<<"Leer Cuadrado"<<endl;
}

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <iomanip>
using namespace std;

#include "derivada.hpp"

void Derivada::SetD(int d) {
    this->d = d;
}

int Derivada::GetD() const {
    return d;
}

void Derivada::imprime() {
    cout << "Estamos en la clase Derivada" << endl;
    cout << "b = " << GetB() << endl;
    cout << "d = " << d << endl;
    cout << endl;
}
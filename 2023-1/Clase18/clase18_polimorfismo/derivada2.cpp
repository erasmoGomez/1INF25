/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <iomanip>
using namespace std;

#include "derivada2.hpp"

void Derivada2::SetDd(int dd) {
    this->dd = dd;
}

int Derivada2::GetDd() const {
    return dd;
}

void Derivada2::imprime() {
    cout << "Estamos en la clase Derivada 2" << endl;
    cout << "b = " << GetB() << endl;
    cout << "dd = " << dd << endl;
    cout << endl;
}
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <iomanip>
using namespace std;
#include "base.hpp"

void Base::SetB(int b) {
    this->b = b;
}

int Base::GetB() {
    return b;
}

void Base::imprime() {
    cout << "estamos en la clase Base" << endl;
    cout << "b= " << b << endl;
    cout << endl;
}
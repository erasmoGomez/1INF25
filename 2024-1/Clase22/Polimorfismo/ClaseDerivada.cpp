/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ClaseDerivada.cpp
 * Author: Erasmo G. Montoya
 * 
 * Created on May 29, 2024, 8:26 AM
 */
#include <iostream>
#include "ClaseDerivada.hpp"
using namespace std;
ClaseDerivada::ClaseDerivada() {
    d=500;
}

ClaseDerivada::ClaseDerivada(const ClaseDerivada& orig) {
}

ClaseDerivada::~ClaseDerivada() {
}

void ClaseDerivada::SetD(int d) {
    this->d = d;
}

int ClaseDerivada::GetD() const {
    return d;
}

void ClaseDerivada::mostrar(){
    cout<<"Clase Derivada"<<endl;
    cout<<d<<endl;
}

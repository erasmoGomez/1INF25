/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ClaseDerivada2.cpp
 * Author: Erasmo G. Montoya
 * 
 * Created on May 29, 2024, 8:27 AM
 */
#include <iostream>
#include "ClaseDerivada2.hpp"
using namespace std;
ClaseDerivada2::ClaseDerivada2() {
    d2 = 600;
}

ClaseDerivada2::ClaseDerivada2(const ClaseDerivada2& orig) {
}

ClaseDerivada2::~ClaseDerivada2() {
}

void ClaseDerivada2::SetD2(int d2) {
    this->d2 = d2;
}

int ClaseDerivada2::GetD2() const {
    return d2;
}

void ClaseDerivada2::mostrar(){
    cout<<"Clase Derivada 2"<<endl;
    cout<<d2<<endl;
}
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Derivada2.cpp
 * Author: ASUS
 * 
 * Created on October 24, 2023, 9:36 AM
 */
#include <iostream>
#include <iomanip>
using namespace std;
#include "Derivada2.hpp"

Derivada2::Derivada2() {
}

Derivada2::Derivada2(const Derivada2& orig) {
}

Derivada2::~Derivada2() {
}

void Derivada2::SetD2(int d2) {
    this->d2 = d2;
}

int Derivada2::GetD2() const {
    return d2;
}

void Derivada2::mostrar(){
//    cout<<"Estamos en la clase Derivada2"<<endl;
//    //cout<<"B = "<<Base::GetB()<<endl<<endl;
//    cout<<"B = "<<GetB()<<endl<<endl;
    Base::mostrar();
    cout<<"D2 = "<<d2<<endl<<endl;
}


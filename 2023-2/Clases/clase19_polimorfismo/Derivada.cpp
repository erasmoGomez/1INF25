/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Derivada.cpp
 * Author: ASUS
 * 
 * Created on October 24, 2023, 9:29 AM
 */
#include <iostream>
#include <iomanip>
using namespace std;
#include "Derivada.hpp"

Derivada::Derivada() {
}

Derivada::Derivada(const Derivada& orig) {
}

Derivada::~Derivada() {
}

void Derivada::SetD(int d) {
    this->d = d;
}

int Derivada::GetD() const {
    return d;
}

void Derivada::mostrar(){
    cout<<"Estamos en la clase Derivada"<<endl;
    //cout<<"B = "<<Base::GetB()<<endl<<endl;
    cout<<"B = "<<GetB()<<endl<<endl;
    cout<<"D = "<<d<<endl<<endl;
}


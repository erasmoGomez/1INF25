/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Base.cpp
 * Author: ASUS
 * 
 * Created on October 24, 2023, 9:25 AM
 */
#include <iostream>
#include <iomanip>
using namespace std;
#include "Base.hpp"

Base::Base() {
}

Base::Base(const Base& orig) {
}

Base::~Base() {
}

void Base::SetB(int b){
    this->b = b;
}

int Base::GetB() const{
    return this->b;
}

void Base::mostrar(){
    cout<<"Estamos en la clase Base"<<endl;
    cout<<"B = "<<b<<endl<<endl;
}
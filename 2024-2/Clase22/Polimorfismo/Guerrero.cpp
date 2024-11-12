/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Guerrero.cpp
 * Author: Erasmo G. Montoya
 * 
 * Created on October 28, 2024, 6:09 PM
 */

#include "Guerrero.hpp"

Guerrero::Guerrero() {
}

Guerrero::Guerrero(const Guerrero& orig) {
}

Guerrero::~Guerrero() {
}

void  Guerrero::realizarAccion(){
    cout<<"El guerrero está atacando..."<<endl;
}

void  Guerrero::realizarAccionPura(){
    cout<<"El guerrero está atacando puramente..."<<endl;
}

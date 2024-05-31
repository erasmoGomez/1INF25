/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ClaseBase.cpp
 * Author: Erasmo G. Montoya
 * 
 * Created on May 29, 2024, 8:24 AM
 */
#include <iostream>
#include "ClaseBase.hpp"
using namespace std;
ClaseBase::ClaseBase() {
    b=100;
}

ClaseBase::ClaseBase(const ClaseBase& orig) {
}

ClaseBase::~ClaseBase() {
}

void ClaseBase::SetB(int b) {
    this->b = b;
}

int ClaseBase::GetB() const {
    return b;
}


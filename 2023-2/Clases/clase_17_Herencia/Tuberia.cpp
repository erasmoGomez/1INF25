/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tuberia.cpp
 * Author: ASUS
 * 
 * Created on October 17, 2023, 9:49 AM
 */

#include "Tuberia.hpp"
#define PI 3.1415
Tuberia::Tuberia() {
}

Tuberia::Tuberia(const Tuberia& orig) {
}

Tuberia::~Tuberia() {
}

double Tuberia::Volumen(){
    return Cilindro::Volumen() - PI*radioInterior*Cilindro::GetAltura();
}
double Tuberia::Area(){
    return Cilindro::Area() - 2*PI*radioInterior*radioInterior;
}

//double Tuberia::Volumen(){
//    return Area()*Cilindro::GetAltura();
//}
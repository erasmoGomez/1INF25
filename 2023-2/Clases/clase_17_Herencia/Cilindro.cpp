/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Cilindro.cpp
 * Author: ASUS
 * 
 * Created on October 17, 2023, 9:25 AM
 */

#include "Cilindro.hpp"
#include <iostream>
#include <iomanip>
using namespace std;
Cilindro::Cilindro() {
}

Cilindro::Cilindro(const Cilindro& orig) {
}

Cilindro::~Cilindro() {
}

void Cilindro::SetAltura(double a){
    altura = a;
}
double Cilindro::GetAltura() const{
    return this->altura;
}
double Cilindro::Volumen(){
    return altura*Area();
}
double Cilindro::Area_Superficie(){
    return 2*Area() + Circunferencia()*altura;
}
void Cilindro::MostrarResultados(){
    Circulo::MostrarResultados();
    cout<<"Volumen:      "<<setw(10)<<Volumen()<<endl;
    cout<<"Area de la Superficie:      "<<setw(10)<<Area_Superficie()<<endl;
}


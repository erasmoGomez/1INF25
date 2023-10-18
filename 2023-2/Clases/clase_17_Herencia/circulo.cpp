/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   circulo.cpp
 * Author: ASUS
 * 
 * Created on October 17, 2023, 9:14 AM
 */

#include "circulo.hpp"
#include <iostream>
#include <iomanip>
using namespace std;
#define PI 3.141592
Circulo::Circulo() {
}

Circulo::Circulo(const Circulo& orig) {
}

Circulo::~Circulo() {
}

void Circulo::SetRadio(double radio){
    this->radio = radio;
}
double Circulo::GetRadio(){
    return this->radio;
}
double Circulo::Area(){
    return PI*radio*radio;
}
double Circulo::Circunferencia(){
    return 2*PI*radio;
}
void Circulo::MostrarResultados(){
    cout.precision(2);
    cout<<fixed;
    cout<<"Radio:      "<<setw(10)<<radio<<endl;
    cout<<"Area:      "<<setw(10)<<Area()<<endl;
    cout<<"Circunferencia:      "<<setw(10)<<Circunferencia()<<endl;
}


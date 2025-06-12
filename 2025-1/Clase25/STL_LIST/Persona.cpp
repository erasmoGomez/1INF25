/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Persona.cpp
 * Author: hecto
 * 
 * Created on June 11, 2025, 4:51 PM
 */

#include <valarray>

#include "Persona.hpp"

Persona::Persona() {
}

Persona::Persona(const Persona& orig) {
    *this = orig;
}

Persona::~Persona() {
}

void Persona::SetSueldo(double sueldo) {
    this->sueldo = sueldo;
}

double Persona::GetSueldo() const {
    return sueldo;
}

void Persona::SetDni(int dni) {
    this->dni = dni;
}

int Persona::GetDni() const {
    return dni;
}

void Persona::SetNombre(string nombre) {
    this->nombre = nombre;
}

string Persona::GetNombre() const {
    return nombre;
}

void Persona::leer(){
    char buffer[50];
    cin>>dni;
    if(cin.eof())return;
    cin.get();
    cin.getline(buffer, 60, ',');
    nombre = buffer; // string -> char* ya tiene la sobrecarga del operador = dentro d sus especificacion
    cin>>sueldo;
    cin.get();
}

void Persona::imprimir() const{
    cout.precision(2);
    cout<<fixed;
    cout<<right<<setw(10)<<dni<<" "<<left<<setw(30)<<nombre;
    cout<<right<<setw(10)<<sueldo<<endl;
}

void Persona::operator =(const class Persona&p){
    nombre = p.nombre;
    dni = p.dni;
    sueldo = p.sueldo;
}

void operator>>(istream& input, class Persona& p){
    p.leer();
}

ostream& operator<<(ostream& output, const class Persona & p){
    p.imprimir();
    return output;
}
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   persona.cpp
 * Author: Erasmo G. Montoya
 * 
 * Created on November 12, 2024, 5:53 PM
 */

#include "persona.hpp"

Persona::Persona() {
}

Persona::Persona(const Persona& orig) {
    *this = orig;
}

Persona::~Persona() {
}

Persona::Persona(string nombre, int edad){
    this->nombre = nombre;
    this->edad = edad;
}

bool Persona::operator<(const Persona& p)const{
    if(nombre == p.nombre)
        return edad<p.edad;
    return nombre<p.nombre;
}

void Persona::imprimir_persona()const{
    cout<<"Nombre: "<<nombre<<", Edad: "<<edad<<endl;
}
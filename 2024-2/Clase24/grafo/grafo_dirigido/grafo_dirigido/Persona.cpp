/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Persona.cpp
 * Author: alulab14
 * 
 * Created on 15 de junio de 2024, 08:54 AM
 */

#include "Persona.h"

Persona::Persona(string nombre, int edad) {
    this->nombre = nombre;
    this->edad = edad;
}

Persona::Persona(const Persona& orig) {
    *this = orig;
}

void Persona::imprimirPersona() const {
    cout << "Nombre: " << nombre << ", Edad: " << edad << endl;
}

bool Persona::operator==(const Persona& otra) const {
    return nombre == otra.nombre and edad == otra.edad;
}

bool Persona::operator<(const Persona& otra) const {
    if (nombre == otra.nombre) {
        return edad < otra.edad;
    }
    return nombre < otra.nombre;
}
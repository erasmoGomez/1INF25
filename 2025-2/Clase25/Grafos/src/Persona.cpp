//
// Created by Erasmo on 11/11/25.
//

#include "Persona.hpp"
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
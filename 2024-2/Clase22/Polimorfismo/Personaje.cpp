/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Personaje.hpp"

Personaje::Personaje() {
    cout<<"hola"<<endl;
    poder = 0;
    nombre = nullptr;
}

void Personaje::SetPoder(int poder) {
    this->poder = poder;
}

int Personaje::GetPoder() const {
    return poder;
}

void Personaje::SetNombre(char* nombre) {
    if(this->nombre !=nullptr) delete this->nombre;
    this->nombre = new char[strlen(nombre)+1];
    strcpy(this->nombre, nombre);
}

void Personaje::GetNombre(char* nombre) const{
    if(this->nombre ==nullptr) nombre[0] = '\0';
    else
        strcpy(nombre, this->nombre);
}

Personaje::Personaje(const Personaje& orig) {
    *this = orig;
}

void Personaje::operator=(const Personaje& p) {
    char buffer_nombre[20];
    p.GetNombre(buffer_nombre);
    SetNombre(buffer_nombre);
    poder = p.GetPoder();
}

void Personaje::realizarAccion(){
    cout<<"El personaje está descansando..."<<endl;
}
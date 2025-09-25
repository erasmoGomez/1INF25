//
// Created by Erasmo on 24/09/25.
//

#include "Heroe.hpp"

Heroe::Heroe() {
    cout<<"Estoy en el constructor por defecto"<<endl;
    this->id = nullptr; // Totalmente obligatorio
    this->nombre = nullptr; //Totalmente obligatorio
    this->defensa = 0;
    this->fuerza = 0;
    this->hp = 100;
    this->posx = 10;
    this->posy = 10;
}

void Heroe::getId(char * id) const {
    if(this->id == nullptr) id[0] = '\n';
    else strcpy(id, this->id);
}

void Heroe::setId(const char *id) {
    if(this->id !=nullptr) delete this->id;
    this->id = new char[strlen(id) +1];
    strcpy(this->id, id);
}

void Heroe::setNombre(const char *nombre) {
    if(this->nombre != nullptr) delete this->nombre;
    this->nombre = new char[strlen(nombre) +1];
    strcpy(this->nombre, nombre);
}

void Heroe::getNombre(char *nombre) const{
    if(this->nombre == nullptr) nombre[0] = '\n';
    else strcpy(nombre, this->nombre);
}

int Heroe::getHp() const {
    return hp;
}

void Heroe::setHp(int hp) {
    Heroe::hp = hp;
}

double Heroe::getFuerza() const {
    return fuerza;
}

void Heroe::setFuerza(double fuerza) {
    Heroe::fuerza = fuerza;
}

double Heroe::getDefensa() const {
    return defensa;
}

void Heroe::setDefensa(double defensa) {
    Heroe::defensa = defensa;
}

int Heroe::getPosx() const {
    return posx;
}

void Heroe::setPosx(int posx) {
    Heroe::posx = posx;
}

int Heroe::getPosy() const {
    return posy;
}

void Heroe::setPosy(int posy) {
    Heroe::posy = posy;
}


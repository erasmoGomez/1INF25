/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Heroe.cpp
 * Author: hecto
 * 
 * Created on May 6, 2025, 5:55 PM
 */

#include "Heroe.hpp"

Heroe::Heroe() {
    cout << "Constructor por Defecto" << endl;
    hp = 100;
    id = nullptr;
    nombre = nullptr;
    posX = 0;
    posY = 0;
}

Heroe::Heroe(int hp, double fuerza, double defensa) {
    cout << "Constructor por Parametros" << endl;
    this->hp = hp;
    this->fuerza = fuerza;
    this->defensa = defensa;
}

//Heroe::Heroe(const Heroe& orig) {
//}
//
//Heroe::~Heroe() {
//}

void Heroe::mostrar_info(ofstream& output) {
    output << "ID: " << id << endl;
    output << "Nombre: " << nombre << endl;
    output << "HP: " << hp << endl;
    output << "FUERZA: " << fuerza << endl;
    output << "DEFENSA: " << defensa << endl;
    output << "POSX: " << posX << endl;
    output << "POSY: " << posY << endl;
}

void Heroe::setPosY(int posY) {
    this->posY = posY;
}

int Heroe::getPosY() const {
    return posY;
}

void Heroe::setPosX(int posX) {
    this->posX = posX;
}

int Heroe::getPosX() const {
    return posX;
}

void Heroe::setDefensa(double defensa) {
    this->defensa = defensa;
}

double Heroe::getDefensa() const {
    return defensa;
}

void Heroe::setFuerza(double fuerza) {
    this->fuerza = fuerza;
}

double Heroe::getFuerza() const {
    return fuerza;
}

void Heroe::setHp(int hp) {
    this->hp = hp;
}

int Heroe::getHp() const {
    return hp;
}

void Heroe::setNombre(const char* nombre) {
    if (this->nombre != nullptr) delete this->nombre;
    this->nombre = new char[strlen(nombre) + 1];
    strcpy(this->nombre, nombre);
}

void Heroe::getNombre(char* nombre) const {
    if(this->nombre == nullptr) nombre[0] = '\0';
    else strcpy(nombre, this->nombre);
}

void Heroe::setId(const char* id) {
    if (this->id != nullptr) delete this->id;
    this->id = new char[strlen(id) + 1];
    strcpy(this->id, id);
}

void Heroe::getId(char* id) const {
    if(this->id == nullptr) id[0] = '\0';
    else strcpy(id, this->id);
}

void Heroe::cargar_info(ifstream& input) {
    //H001,Ayla,100,15,5,1,0
    char buffer[20];
    input.getline(buffer, 20, ',');
    setId(buffer);
    input.getline(buffer, 20, ',');
    setNombre(buffer);
    input>>hp;
    input.get();
    input>>fuerza;
    input.get();
    input>>defensa;
    input.get();
    input>>posX;
    input.get();
    input>>posY;
    input.get();
}
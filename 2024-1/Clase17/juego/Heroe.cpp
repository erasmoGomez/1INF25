/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Heroe.hpp"

Heroe::Heroe() {
    nombre = nullptr;
}

void Heroe::setPosy(int posy) {
    this->posy = posy;
}

int Heroe::getPosy() const {
    return posy;
}

void Heroe::setPosx(int posx) {
    this->posx = posx;
}

int Heroe::getPosx() const {
    return posx;
}

void Heroe::setMana(double mana) {
    this->mana = mana;
}

double Heroe::getMana() const {
    return mana;
}

void Heroe::setHp(int hp) {
    this->hp = hp;
}

int Heroe::getHp() const {
    return hp;
}

void Heroe::setNombre(const char* nombre) {
    if(this->nombre!=nullptr) delete this->nombre;
    this->nombre = new char[strlen(nombre)+1];
    strcpy(this->nombre, nombre);
}

void Heroe::getNombre(char* nombre) const {
    if(this->nombre==nullptr) nombre[0] = 0;
    else strcpy(nombre, this->nombre);
}

void Heroe::leer(ifstream &input){
    char buffer[20],extra;
    //Teemo,500, 25.3, 15, 15
    input.getline(buffer, 20, ',');
    input>>hp>>extra;
    input>>mana>>extra;
    input>>posx>>extra;
    input>>posy;
    input.get();
    setNombre(buffer);
}

void operator>>(ifstream& input, Heroe& h){
    h.leer(input);
}
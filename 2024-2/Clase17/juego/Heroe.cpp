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
    //Teemo,500, 25.3, 15, 15, 100, 100
    input.getline(buffer, 20, ',');
    input>>hp>>extra;
    input>>mana>>extra;
    input>>posx>>extra;
    input>>posy>>extra;
    input>>ataque>>extra;
    input>>defensa;
    input.get();
    setNombre(buffer);
}

void Heroe::mostrar(ofstream &output){
    output<<"Nombre: " << nombre<<endl;
    output<<"Vida: " << hp<<endl;
    output<<"Ataque: " << ataque<<endl;
    output<<"Defensa: " << defensa<<endl;
    mochila.mostrar(output);
}

void Heroe::operator++(int){
    //W
    //setPosx(this->posx-1);
    setPosx(posx-1);
    //setPosx(getPosx()-1);
}

void Heroe::operator++(){
    //S
    setPosx(posx+1);
}

void Heroe::operator--(int){
    //D
    setPosy(posy+1);
}

void Heroe::operator--(){
    //A
    setPosy(posy-1);
}

void Heroe::agregar_mochila(ifstream& input, char* tipo){
    //Heroe- Mochila- Item - Consumible/Armadura/Arma
    mochila.agregar_item(input, tipo);
}

void operator>>(ifstream& input, Heroe& h){
    h.leer(input);
}
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <iostream>
#include <cstring>
#include <iomanip>
#include "hero.hpp"

using namespace std;

Heroe::Heroe(){
    cout<<"Estoy en el constructor por defecto"<<endl;
    nombre = nullptr;
    hp = 15000;
}

Heroe::Heroe(const char*n, int hp){
    cout<<"Estoy en el constructor con parametros"<<endl;
//    this->nombre = new char[strlen(n)+1];
//    strcpy(this->nombre,n);
//    Heroe::setNombre(n);
    setNombre(n);
    //this->hp = hp;
    setHp(hp);
}

Heroe::Heroe(const Heroe& h){
}

Heroe::~Heroe(){
    cout<<"Estoy en el destructor"<<endl;
    if(nombre) delete nombre;
}

void Heroe::crear(){
    char buffer[50]={"Heroe 1"};
    hp = 1000;
    posx = 100;
    posy = 200;
    mana = 100.0;
    
    nombre = new char[strlen(buffer)+1];
    strcpy(nombre, buffer);
}

void Heroe::mostrar(){
    cout<<"Nombre del Hero: "<<nombre<<endl;
    cout<<"HP: "<<setw(10)<<hp<<setw(10)<<"Mana: "<<mana<<endl;
    cout<<"X: "<<setw(5)<<posx<<setw(5)<<"Y: "<<posy<<endl; 
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

void Heroe::curar(int hp){
    this->hp +=hp;
}

void Heroe::mover(int x, int y, double m){
    posx+=x;
    posy+=y;
    mana+=m;
}

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <valarray>

#include "Heroe.hpp"

void Heroe::crear(){
    char buffer[20] = {"Erasmo Gomez"};
    vida = 1000;
    setVida(1000);
    mana = 100.0;
    posX = 5;
    posY = 5;
    nombre = new char[strlen(buffer)+1];
    strcpy(nombre, buffer);
}

void Heroe::mostrar(){
    cout<<"Nombre: "<< nombre<<endl;
    cout<<"Vida: "<<vida<<endl;
    cout<<"Mana: "<<mana<<endl;
    cout<<"Posicion: "<<posX<<"  "<<posY<<endl;
}

Heroe::Heroe(){
    cout<<"Estoy en el constructor por defecto"<<endl;
    nombre = nullptr;
    vida = 0;
    posX = 0;
    posY = 0;
    mana = 0;
}
Heroe::Heroe(const char*nombre, int vida){
    cout<<"Constructor con parametros"<<endl;
    this->vida = vida;
    this->nombre = new char[strlen(nombre)+1];
    strcpy(this->nombre, nombre);
    mana = 0;
    posX=0;posY=0;
}

Heroe::Heroe(const Heroe& h){
}

void Heroe::mover(int x, int y){
    posX = x;
    posY = y;
}
void Heroe::curar(int hp){
    vida += hp;
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

void Heroe::setMana(double mana) {
    this->mana = mana;
}

double Heroe::getMana() const {
    return mana;
}

void Heroe::setVida(int vida) {
    this->vida = vida;
}

int Heroe::getVida() const {
    return vida;
}

//void Heroe::setNombre(char* nombre) {
//    this->nombre = nombre;
//}
//
//char* Heroe::getNombre() const {
//    return nombre;
//}

void Heroe::setNombre(const char* nombre){
    if(this->nombre!=nullptr) delete this->nombre;
    this->nombre = new char[strlen(nombre)+1];
    strcpy(this->nombre, nombre);
}

void Heroe::getNombre(char* nombre) const{
    if(this->nombre == nullptr) nombre[0] = '\0';
    else strcpy(nombre, this->nombre);
}
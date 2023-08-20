/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "hero.hpp"

Hero::Hero() {
    nombre = nullptr;
}

Hero::Hero(const char *nomb, char c, int hp, int x, int y) {
    nombre = nullptr;
    this->hp = hp;
    posX = x;
    posY = y;
    tileChar = c;
    SetNombre(nomb);

}

Hero::~Hero() {
    if (nombre != nullptr)delete nombre;
}

void Hero::SetPosY(int posY) {
    this->posY = posY;
}

int Hero::GetPosY() const {
    return posY;
}

void Hero::SetPosX(int posX) {
    this->posX = posX;
}

int Hero::GetPosX() const {
    return posX;
}

void Hero::SetHp(int hp) {
    this->hp = hp;
}

int Hero::GetHp() const {
    return hp;
}

void Hero::SetTileChar(char tileChar) {
    this->tileChar = tileChar;
}

char Hero::GetTileChar() const {
    return tileChar;
}

void Hero::SetNombre(const char* cad) {
    if (nombre != nullptr) delete nombre;
    nombre = new char[strlen(cad) + 1];
    strcpy(nombre, cad);
}

void Hero::GetNombre(char * cad) const {
    if (nombre == nullptr) cad[0] = 0;
    else strcpy(cad, nombre);
}

void Hero::Move(int newX, int newY){
    SetPosX(newX);
    SetPosY(newY);
    
}

void Hero::Move(int pasos, char dir){
    for(int i=0; i<pasos; i++){
        if(dir == 'R'){
            SetPosX(posX + 1);
            SetPosY(posY);
        }
        if(dir == 'I'){
            SetPosX(posX - 1);
            SetPosY(posY);
        }
        if(dir == 'U'){
            SetPosX(posX);
            SetPosY(posY - 1);
        }
        if(dir == 'D'){
            SetPosX(posX);
            SetPosY(posY + 1);
        }
    } 
}

void operator<<(ofstream &arch, const class Hero &h) {
    char nombre[60];
    h.GetNombre(nombre);
    arch << left << "Pos X:" << right << setw(25) << h.GetPosX() << endl;
    arch << left << "Pos Y:" << right << setw(25) << h.GetPosY() << endl;
    arch << left << setw(10) << "Nombre Heroe: " << nombre << endl << setw(10) << "HP: " << h.GetHp() << endl;
}


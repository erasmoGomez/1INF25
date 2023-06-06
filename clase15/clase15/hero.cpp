/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "functions.hpp"
#include "hero.hpp"

Hero::Hero() {
    nombre = nullptr;
}

Hero::Hero(const char *nom, char c, int h, int x, int y) {
    nombre = nullptr;
    hp = h;
    posX = x;
    posY = y;
    tileChar = c;
    SetNombre(nom);
}

Hero::Hero(Hero &h) {
    hp = h.hp;
    posX = h.posX;
    posY = h.posY;
    tileChar = h.tileChar;
    char nomb[60];
    h.GetNombre(nomb);
    nombre = new char[strlen(nomb) + 1];
    strcpy(nombre, nomb);
    //SetNombre(nomb);
}

Hero::~Hero() {
    if (nombre != nullptr)delete nombre;
}

void Hero::SetHp(int hp) {
    this->hp = hp;
}

void Hero::SetPosX(int posX) {
    this->posX = posX;
}

void Hero::SetPosY(int posY) {
    this->posY = posY;
}

void Hero::SetNombre(const char* cad) {
    if (nombre != nullptr) delete nombre;
    nombre = new char[strlen(cad) + 1];
    strcpy(nombre, cad);
}

void Hero::SetTileChar(char tileChar) {
    this->tileChar = tileChar;
}

int Hero::GetPosY() const {
    return posY;
}

int Hero::GetPosX() const {
    return posX;
}

int Hero::GetHp() const {
    return hp;
}

void Hero::GetNombre(char *cad) const {
    if (nombre == nullptr) cad[0] = 0;
    else strcpy(cad, nombre);
}

char Hero::GetTileChar() const {
    return tileChar;
}

void Hero::move(int newX, int newY) {
    SetPosX(newX);
    SetPosY(newY);
}

void operator<<(ofstream &arch, const class Hero &h) {
    char nombre[60];
    h.GetNombre(nombre);
    arch << left << "Pos X:" << right << setw(25) << h.GetPosX() << endl;
    arch << left << "Pos Y:" << right << setw(25) << h.GetPosY() << endl;
    arch << left << setw(10) << "Nombre Heroe: " << nombre << endl << setw(10) << "HP: " << h.GetHp() << endl;
}

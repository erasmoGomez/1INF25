/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Hero.cpp
 * Author: ASUS
 * 
 * Created on October 18, 2023, 7:43 AM
 */

#include "Hero.hpp"

Hero::Hero() {
    name = nullptr;
}

Hero::Hero(const Hero& orig) {
}

Hero::~Hero() {
}

void Hero::SetHp(int hp) {
    this->hp = hp;
}

int Hero::GetHp() const {
    return hp;
}

void Hero::SetAtt(int att) {
    this->att = att;
}

int Hero::GetAtt() const {
    return att;
}

void Hero::SetPosy(int posy) {
    this->posy = posy;
}

int Hero::GetPosy() const {
    return posy;
}

void Hero::SetPosx(int posx) {
    this->posx = posx;
}

int Hero::GetPosx() const {
    return posx;
}

void Hero::SetName(const char* name) {
    if(this->name != nullptr) delete this->name;
    this->name = new char[strlen(name)+1];
    strcpy(this->name, name);
}

void Hero::GetName(char * name) const {
    if(this->name == nullptr) name[0] = 0;
    else{
        strcpy(name, this->name);
    }
}

void Hero::SetCode(int code) {
    this->code = code;
}

int Hero::GetCode() const {
    return code;
}

void Hero::mostrar_hero(ofstream &output) const{
    char name[10];
    GetName(name);
    output<<left<<setw(COLUMN_SIZE)<<GetCode();
    output<<left<<setw(COLUMN_SIZE)<<name;
    output<<left<<setw(COLUMN_SIZE)<<GetHp();
    output<<right<<setw(COLUMN_SIZE)<<GetAtt()<<endl;
}

void operator>>(ifstream& input, class Hero &h) {
    int cod, hp, att, x, y;
    char name[10]{' '};
    input>>cod;
    if (input.eof())return;
    input.get();
    input.getline(name,10,',');
    input>>hp;
    input.get();
    input>>att;
    input.get();
    input>>x;
    input.get();
    input>>y;
    input.get();
    h.SetCode(cod);
    h.SetName(name);
    h.SetHp(hp);
    h.SetAtt(att);
    h.SetPosx(x);
    h.SetPosy(y);
}

void operator<<(ofstream& output, const class Hero &h) {
    h.mostrar_hero(output);
}
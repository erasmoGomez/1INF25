/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Item.cpp
 * Author: ASUS
 * 
 * Created on October 18, 2023, 7:47 AM
 */

#include "Item.hpp"

Item::Item() {
    name = nullptr;
    description = nullptr;
}

Item::Item(const Item& orig) {
}

Item::~Item() {
}

void Item::SetValue(int value) {
    this->value = value;
}

int Item::GetValue() const {
    return value;
}

void Item::SetCodigo_hero(int codigo_hero) {
    this->codigo_hero = codigo_hero;
}

int Item::GetCodigo_hero() const {
    return codigo_hero;
}

void Item::SetDescription(const char* description) {
    if (this->description != nullptr) delete this-> description;
    this->description = new char[strlen(description) + 1];
    strcpy(this->description, description);
    
}

void Item::GetDescription(char *description) const {
    if (this->description == nullptr) description[0] = 0;
    else strcpy(description, this->description);
}

void Item::SetName(const char* name) {
    if (this->name != nullptr) delete this-> name;
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}

void Item::GetName(char *name) const {
    if (this->name == nullptr) name[0] = 0;
    else strcpy(name, this->name);
}

void Item::SetCode(int code) {
    this->code = code;
}

int Item::GetCode() const {
    return code;
}


void Item::mostrar_item(ofstream &output) const{
    char name[30]{};
    char description[100]{};
    GetName(name);
    GetDescription(description);
    output<<left<<setw(COLUMN_SIZE)<<GetCode();
    output<<left<<setw(3*COLUMN_SIZE)<<name;
    output<<left<<setw(5*COLUMN_SIZE)<<description;
    output<<right<<setw(COLUMN_SIZE)<<GetValue()<<endl;
}

void Item::asignar(int code, const char* name, const char* desc, int codeh, int value){
    SetCode(code);
    SetName(name);
    SetDescription(desc);
    SetCodigo_hero(codeh);
    SetValue(value);
}

void Item::SetHp(int hp) {
    this->hp = hp;
}

int Item::GetHp() const {
    return hp;
}

void Item::SetAtt(int att) {
    this->att = att;
}

int Item::GetAtt() const {
    return att;
}

void operator>>(ifstream& input, class Item &item) {
    int code, value, code_hero;
    char name[30]{}, type[30]{}, description[100]{};

    input>>code;
    if (input.eof())return;
    input.get();
    input.getline(name, 30, ',');
    input.getline(type, 30, ',');
    input.getline(description, 100, ',');
    input>>value;
    input.get();
    input>>code_hero;
    input.get();
    
    item.SetCode(code);
    item.SetName(name);
    item.SetDescription(description);
    item.SetValue(value);
    item.SetCodigo_hero(code_hero);

}

void operator<<(ofstream& output, const class Item &i) {
    i.mostrar_item(output);
}
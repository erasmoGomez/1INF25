/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   hero.cpp
 * Author: ASUS
 * 
 * Created on October 31, 2023, 8:43 AM
 */

#include "Hero.hpp"

Hero::Hero() {
    name=nullptr;
}

Hero::Hero(const Hero& orig) {
    name=nullptr;
    *this=orig;
}

Hero::~Hero() {
    if(name!=nullptr)delete name;
}

void Hero::SetAtt(double att) {
    this->att = att;
}

double Hero::GetAtt() const {
    return att;
}

void Hero::SetName(const char* name) {
    if(this->name != nullptr) delete this->name;
    this->name = new char[strlen(name)+1];
    strcpy(this->name, name);
}

void Hero::GetName(char * name) const {
    if (this->name == nullptr) name[0] = 0;
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

void Hero::operator=(const class Hero &h) {
    char name_h[100];
    code = h.GetCode(); //usando getter
    att = h.att; // usando dentro de la clase atributos
    h.GetName(name_h);
    SetName(name_h);
}

//bool Hero::operator>(const class Hero& h) {
//    return att > h.GetAtt();
//}

bool Hero::operator>(const class Hero& h) {
    char name_buffer[20];
    h.GetName(name_buffer);
    if(strcmp(this->name, name_buffer)>0)
        return true;
    else
        return false;
}

bool Hero::operator == (const char* name){
    if(strcmp(this->name, name)==0)
        return true;
    else
        return false;
}

bool Hero::operator>(const char* name) {
    if(strcmp(this->name, name)>0)
        return true;
    else
        return false;
}

ifstream & operator>>(ifstream &input, class Hero & h){
    int code;
    char name[100];
    double att;
    input>>code;
    if(input.eof()) return input;
    input.get();
    input.getline(name, 100, ',');
    input>>att;
    input.get();
    
    h.SetAtt(att);
    h.SetName(name);
    h.SetCode(code);
    return input;
            
}

//ofstream & operator<<(ofstream &output, const class Hero & h){
//    char nombre[100];
//    h.GetName(nombre);
//    output<<left<<setw(5)<<h.GetCode()<<left<<setw(15)<<nombre<<right<<setw(10)<<h.GetAtt()<<endl;
//    return output;
//}

ostream & operator<<(ostream &output, const class Hero & h){
    char nombre[100];
    h.GetName(nombre);
    output<<left<<setw(5)<<h.GetCode()<<left<<setw(15)<<nombre<<right<<setw(10)<<h.GetAtt()<<endl;
    return output;
}
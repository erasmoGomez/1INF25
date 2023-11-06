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

#include "hero.hpp"

hero::hero() {
}

hero::hero(const hero& orig) {
}

hero::~hero() {
}

void hero::SetAtt(double att) {
    this->att = att;
}

double hero::GetAtt() const {
    return att;
}

void hero::SetName(const char* name) {
    if(this->name != nullptr) delete this->name;
    this->name = new char[strlen(name)+1];
    strcpy(this->name, name);
}

void hero::GetName(char * name) const {
    if (this->name == nullptr) name[0] = 0;
    else{
        strcpy(name, this->name);
    }
}

void hero::SetCode(int code) {
    this->code = code;
}

int hero::GetCode() const {
    return code;
}

void hero::operator=(const class hero &h) {
    char name_h[100];
    code = h.GetCode(); //usando getter
    att = h.att; // usando dentro de la clase atributos
    h.GetName(name_h);
    SetName(name_h);
}

bool hero::operator>(const class hero& h) {
    return att > h.GetAtt();
}

ifstream & operator>>(ifstream &input, class hero & h){
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

ofstream & operator<<(ofstream &output, class hero & h){
    char nombre[100];
    h.GetName(nombre);
    output<<setw(20)<<h.GetCode()<<setw(60)<<nombre<<setw(20)<<h.GetAtt()<<endl;
    return output;
}
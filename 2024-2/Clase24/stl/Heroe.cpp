/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Heroe.cpp
 * Author: Erasmo G. Montoya
 * 
 * Created on June 17, 2024, 5:00 PM
 */

#include "Heroe.hpp"

Heroe::Heroe() {
    nombre=nullptr;
}

Heroe::Heroe(const Heroe& orig) {
    nombre=nullptr;
    *this=orig;
}

Heroe::~Heroe() {
    if(nombre!=nullptr)delete nombre;
}

void Heroe::SetAtaque(double ataque) {
    this->ataque = ataque;
}

double Heroe::GetAtaque() const {
    return ataque;
}

void Heroe::SetNombre(const char* nombre) {
    if(this->nombre != nullptr) delete this->nombre;
    this->nombre = new char[strlen(nombre)+1];
    strcpy(this->nombre, nombre);
}

void Heroe::GetNombre(char * nombre) const {
    if (this->nombre == nullptr) nombre[0] = 0;
    else{
        strcpy(nombre, this->nombre);
    }
}

void Heroe::SetCodigo(int code) {
    this->codigo = codigo;
}

int Heroe::GetCodigo() const {
    return codigo;
}


void Heroe::leer(ifstream &input) {
    char extra, buffer[20];
    //Teemo,500, 25.3, 15, 15
    input>>codigo>>extra;
    input.getline(buffer, 20,',');
    input>>ataque;

    SetNombre(buffer);
}

void Heroe::leer2(ifstream &input) {
    char extra, buffer[20];
    //Teemo,500, 25.3, 15, 15
    input>>codigo>>extra;
    //getline(input,nombre2, ',');
    input.getline(buffer, 20, ',');
    nombre2 = buffer;
    input>>ataque;
}

//void Heroe::leer2(ifstream &input) {
////    char extra, buffer[20];
////    //Teemo,500, 25.3, 15, 15
////    input>>codigo>>extra;
////    input.getline(buffer, 20,',');
////    input>>ataque;
////    nombre2 = buffer
////    input.get(nombre2);
//}

void Heroe::mostrar() const{
    cout<<"Nombre Heroe : "<<nombre<<"   ";
    cout<<"Ataque: "<<ataque<<endl;
}

bool Heroe::operator <(const Heroe &h){
    char buffer_nombre[30];
    h.GetNombre(buffer_nombre);
    if(strcmp(this->nombre, buffer_nombre)<0)
        return true;
    else
        return false;
//    return h.GetAtaque()<ataque;
}

void Heroe::SetNombre2(string nombre2) {
    this->nombre2 = nombre2;
}

string Heroe::GetNombre2() const {
    return nombre2;
}
//
void Heroe::operator = (const class Heroe&h){
    char name_h[30];
    ataque = h.ataque;
    h.GetNombre(name_h);
    this->SetNombre(name_h);
}

void operator >> (ifstream& input, Heroe& h){
    h.leer(input);
}

void operator<<(ostream& output, const Heroe& h) {
    h.mostrar();
}
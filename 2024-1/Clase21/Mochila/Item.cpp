/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Item.cpp
 * Author: Erasmo G. Montoya
 * 
 * Created on May 27, 2024, 5:38 PM
 */

#include "Item.hpp"

Item::Item() {
    equipadoQ = false;
}

Item::Item(const Item& orig) {
}

Item::~Item() {
}

void Item::SetEquipadoQ(bool equipadoQ) {
    this->equipadoQ = equipadoQ;
}

bool Item::GetEquipadoQ() const {
    return equipadoQ;
}

void Item::SetDescripcion(const char* descripcion) {
    if(this->descripcion!=nullptr) delete this->descripcion;
    this->descripcion = new char[strlen(descripcion)+1];
    strcpy(this->descripcion, descripcion);
}

void Item::GetDescripcion(char *descripcion) const {
    if(this->descripcion==nullptr) descripcion[0] = 0;
    else strcpy(descripcion, this->descripcion);
}

void Item::SetNombre(const char* nombre) {
    if(this->nombre!=nullptr) delete this->nombre;
    this->nombre = new char[strlen(nombre)+1];
    strcpy(this->nombre, nombre);
}

void Item::GetNombre(char *nombre) const {
    if(this->nombre==nullptr) nombre[0] = 0;
    else strcpy(nombre, this->nombre);
}

void Item::leer(ifstream& input){
    char _nombre[20], _descripcion[50];
    input.getline(_nombre, 20, ',');
    input.getline(_descripcion, 50, ',');
    SetNombre(_nombre);
    SetDescripcion(_descripcion);
}

void Item::mostrar(ofstream &output){
    output<<setw(20(<<nombre<<setw(50<<descripcion<<endl;
}
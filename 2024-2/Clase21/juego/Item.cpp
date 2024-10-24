/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Item.cpp
 * Author: Erasmo G. Montoya
 * 
 * Created on October 22, 2024, 6:12 PM
 */

#include "Item.hpp"

Item::Item(){
    nombre = nullptr;
    descripcion = nullptr;
    equipadoQ = false;
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

void Item::mostrar(){
    //cout<<"Clase Padre"<<endl;
    cout<<setw(30)<<nombre;
    cout<<setw(70)<<descripcion<<endl;
}

Item::~Item(){
//    cout<<"Estoy en el destructor"<<endl;
    if(nombre!=nullptr){
        delete nombre;
    }
    if(descripcion!=nullptr){
        delete descripcion;
    }
//    cout<<"Eliminado"<<endl;
}

void Item::leer(ifstream &input){
    //Sword,A sharp and sturdy sword.,
    char _nombre[30], _descripcion[70];
    input.getline(_nombre, 30, ',');
    input.getline(_descripcion, 70, ',');
    SetNombre(_nombre);
    SetDescripcion(_descripcion);
}

void Item::SetEquipadoQ(bool equipadoQ) {
    this->equipadoQ = equipadoQ;
}

bool Item::IsEquipadoQ() const {
    return equipadoQ;
}
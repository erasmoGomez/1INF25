/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Item.cpp
 * Author: hecto
 * 
 * Created on May 14, 2025, 5:37 PM
 */

#include "Item.hpp"

Item::Item() {
    nombre = nullptr;
    descripcion = nullptr;
    equipado = false;
}

Item::Item(const Item& orig) {
}

Item::~Item() {
}

void Item::SetNombre(const char* nombre) {
    if (this->nombre != nullptr) delete this->nombre;
    this->nombre = new char[strlen(nombre) + 1];
    strcpy(this->nombre, nombre);
}

void Item::GetNombre(char* nombre) const {
    if (this->nombre == nullptr) nombre[0] = '\0';
    else strcpy(nombre, this->nombre);
}

void Item::SetDescripcion(const char* descripcion) {
    if (this->descripcion != nullptr) delete this->descripcion;
    this->descripcion = new char[strlen(descripcion) + 1];
    strcpy(this->descripcion, descripcion);
}

void Item::GetDescripcion(char* descripcion) const {
    if (this->descripcion == nullptr) descripcion[0] = '\0';
    else strcpy(descripcion, this->descripcion);
}

void Item::SetEquipado(bool equipado) {
    this->equipado = equipado;
}

bool Item::IsEquipado() const {
    return equipado;
}

void Item::leer(ifstream&input){
    //Sword,A sharp and sturdy sword.,147
    char _nombre[50], _descripcion[70];
    input.getline(_nombre, 30, ',');
    input.getline(_descripcion, 70, ',');
    SetNombre(_nombre);
    SetDescripcion(_descripcion);
}

void Item::mostrar(ostream&output) const{
    output<<setw(30)<<left<<nombre;
    output<<setw(50)<<left<<descripcion;
}

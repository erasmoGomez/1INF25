/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Item.hpp"
Item::Item(){
    nombre = nullptr;
    descripcion = nullptr;
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
    cout<<"Clase Padre"<<endl;
    cout<<setw(20)<<nombre;
    cout<<setw(50)<<descripcion<<endl;
}
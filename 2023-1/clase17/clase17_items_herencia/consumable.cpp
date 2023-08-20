/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "functions.hpp"
#include "consumable.hpp"
Consumable::Consumable(){
    caracteristica = 1;
    variacion = 0;
}

Consumable::Consumable(int id, char* name, char* desc, int varia, int carac):  Item(id, name, desc){
    caracteristica = carac;
    variacion = varia;
}

void Consumable::SetCaracteristica(int caracteristica) {
    this->caracteristica = caracteristica;
}

int Consumable::GetCaracteristica() const {
    return caracteristica;
}

void Consumable::SetVariacion(int variacion) {
    this->variacion = variacion;
}

int Consumable::GetVariacion() const {
    return variacion;
}

void Consumable::load_consumable(int id, const char* name, const char* desc, int varia, int carac){
    SetID(id);
    SetName(name);
    SetDescription(desc);
    
    SetVariacion(varia);
    SetCaracteristica(carac);
}

void Consumable::print_consumable(){
    cout<< "/////////////"<<endl;
    char buffer[200];
    cout<<GetID()<<endl;
    GetName(buffer);
    cout<<buffer<<endl;
    GetDescription(buffer);
    cout<<buffer<<endl;
    
    cout<<GetVariacion()<<endl;
    cout<<GetCaracteristica()<<endl;
    cout<< "/////////////"<<endl;
}
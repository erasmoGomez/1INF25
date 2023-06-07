/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "functions.hpp"
#include "item.hpp"

Item::Item(){
    ID = 0;
    name = nullptr;
    description = nullptr;
    type = 0;
}

Item::Item(int id, const char * name, const char * desc, int t){
    name = nullptr;
    description = nullptr;
    ID = id;
    type = t;
    SetName(name);
    SetDescription(desc);
}

void Item::SetType(int type) {
    this->type = type;
}

int Item::GetType() const {
    return type;
}

void Item::SetDescription(const char* buffer) {
    if(description != nullptr) delete description;
    description = new char [strlen(buffer)+1];
    strcpy(description,buffer);
}

void Item::GetDescription(char * buffer) const {
    if(description == nullptr) 
        buffer[0] = 0; // \0
    else
        strcpy(buffer, description);
}

void Item::SetName(const char* buffer) {
    if(name != nullptr) delete name;
    name = new char [strlen(buffer)+1];
    strcpy(name,buffer);
}

void Item::GetName(char* buffer) const {
    if(name == nullptr) 
        buffer[0] = 0; // \0
    else
        strcpy(buffer, name);
}

void Item::SetID(int ID) {
    this->ID = ID;
}

int Item::GetID() const {
    return ID;
}

void operator>>(ifstream & arch, class Item & i){
    int id, type;
    char name[20], desc[200];
    
    arch>>id;
    if(arch.eof()) return;
    arch.get();
    arch.getline(name,20,',');
    arch.getline(desc,200,',');
    arch>>type;
    //asignar a i
    i.SetID(id);
    i.SetName(name);
    i.SetDescription(desc);
    i.SetType(type);
    
}

void operator<<(ofstream & arch, class Item & i){
    char name[20], desc[200];
    i.GetName(name);
    i.GetDescription(desc);
    //imprimir
    arch<<"ID: " <<i.GetID()<<endl;
    arch<<"Name: "<< name<<endl;
    arch<<"Description: "<<desc<<endl;
    arch<<"Type: "<<i.GetType()<<endl;
    
}
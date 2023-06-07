/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "functions.hpp"
#include "item.hpp"
#include "backpack.hpp"
#define LIMIT 200

Backpack::Backpack() {
    limit = 0;
    name = nullptr;
}

void Backpack::operator+=(class Item & i) {
    if (limit == LIMIT) {
        cout << "Ya llegaste al final";
    }
    if (i.GetID() == 0) {
        cout << "Ya llegaste al final";
    }
    //if(items == nulptr) 
    this->items[limit] = i;
    limit = limit + 1;
}

void Backpack::SetLimit(int limit) {
    this->limit = limit;
}

int Backpack::GetLimit() const {
    return limit;
}

void Backpack::SetItem(Item &item, int i) {
    items[i] = item;
}

Item* Backpack::GetItems() {

    return &items[0];
}

Item& Backpack::GetItem(int i) {

    return items[i];
}

void Backpack::SetName(const char* cad) {
    if (name != nullptr) delete name;
    name = new char [strlen(cad) + 1];
    strcpy(name, cad);
}

void Backpack::GetName(char * buffer) const {
    if (name == nullptr)
        buffer[0] = 0; // \0
    else
        strcpy(buffer, name);
}

void Backpack::SetID(int ID) {
    this->ID = ID;
}

int Backpack::GetID() const {
    return ID;
}

void operator>>(ifstream & arch, class Backpack & b) {
    int id, limit, item_id;
    char name[20];
    int ammount;
    cout << "sss" << endl;
    arch>>id;
    cout << id << endl;
    if (arch.eof()) return;
    arch.get();
    arch.getline(name, 20, ',');
    arch>>item_id;
    arch.get();
    arch>>ammount;
    cout << id << endl << name << endl << item_id << endl << ammount << endl;
    //asignar a b
    b.SetID(id);
    cout << b.GetID() << endl;
    char nm[60];
    b.SetName(name);
    b.GetName(nm);
    cout << nm << endl;
    b.SetLimit(1);
    cout << b.GetLimit() << endl;
    Item itin(item_id, "testin");
    //cout<<i.GetID()+10<<endl;
    //b.SetItem(i, 0);
}
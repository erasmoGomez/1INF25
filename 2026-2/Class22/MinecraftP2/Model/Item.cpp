//
// Created by erasmo on 10/21/26.
//

#include "Item.hpp"

int Item::get_id() const {
    return id;
}

void Item::set_id(const int id) {
    this->id = id;
}

string Item::get_name() const {
    return name;
}

void Item::set_name(const string &name) {
    this->name = name;
}

string Item::get_color() const {
    return description;
}

void Item::set_color(const string &color) {
    this->description = color;
}

double Item::get_durability() const {
    return durability;
}

void Item::set_durability(const double durability) {
    this->durability = durability;
}

int Item::get_quantity() const {
    return quantity;
}

void Item::set_quantity(const int quantity) {
    this->quantity = quantity;
}

Item::Item() {
    id = 0;
    durability = 0.0;
    quantity = 3;
    //cout<<"Constructor Clase Item"<<endl;
}

Item::Item(const char *name) {
    id = 0;
    this->name = name;
    durability = 0.0;
}

Item::Item(int id, string name, double durability) {
    this->id = id;
    this->name = name;
    this->durability = durability;
}

void Item::read(ifstream &input) {
    //Bread,Restores hunger,44,4
    getline(input, name, ',');
    getline(input, description, ',');
    input >> durability;
    input.get();
}

void Item::print(ostream &out) const {
    out << setw(30) << get_name();
    out << setw(10) << get_durability() << endl;
}

bool Item::is_empty() const {
    return false;
}

Item::~Item() {
}

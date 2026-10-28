//
// Created by erasmo on 10/21/26.
//

#include "Weapon.hpp"

Weapon::Weapon() {
    cout<<"Constructor Clase Weapon"<<endl;
}

int Weapon::get_damage() const {
    return damage;
}

void Weapon::set_damage(const int damage) {
    this->damage = damage;
}

void Weapon::attack() {
    cout<<"ATACANDO!"<<endl;
}

void Weapon::read(ifstream &input) {
    //Netherite Sword,Highly durable melee weapon,104,1
    Item::read(input);
    //1
    input>>damage;
    input.get();
    input.get();
}

void Weapon::use() {
    attack();
}

//
// Created by erasmo on 9/29/26.
//

#include "Creeper.hpp"

int Creeper::get_health() const {
    return health;
}

void Creeper::set_health(const int health) {
    this->health = health;
}

int Creeper::get_damage() const {
    return damage;
}

void Creeper::set_damage(const int damage) {
    this->damage = damage;
}

bool Creeper::is_charged() const {
    return charged;
}

void Creeper::set_charged(const bool charged) {
    this->charged = charged;
}

Creeper::Creeper() {
    health = 100;
    damage = 200;
    charged = false;
}

void Creeper::explode() {
    cout<<"BOOOOM!"<<endl;
    this->set_health(0);
    this->charged = false;
}

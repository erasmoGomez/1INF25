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
    cout<<"Estoy siendo llamado como constructor por defecto"<<endl;
    health = 100;
    damage = 200;
    charged = false;
}

Creeper::Creeper(const int health, const int damage, const bool charged) {
    cout<<"Estoy siendo llamado como constructor con parametros"<<endl;
    this->health = health;
    this->damage = damage;
    this->charged = charged;
}

Creeper::Creeper(bool charged) {
    cout<<"Estoy siendo llamado como constructor con parametros pero solo con 1"<<endl;
    this->damage = 100;
    this->health = 100;

    this->charged = charged;
}

Creeper::Creeper(const Creeper &c) {
    cout<<"Estoy siendo llamado como constructor copia"<<endl;
    this->health = c.health;
    this->damage = c.damage;
    this->charged = c.charged;
}

Creeper::~Creeper() {
    cout<<"Destructor de Creeper"<<endl;
}

void Creeper::explode() {
    cout<<"BOOOOM!"<<endl;
    this->set_health(0);
}

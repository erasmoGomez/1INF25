#include "Player.hpp"

Player::Player() {
    x = 10;
    y = 10;
    z = 10;
    health = 100;
    name = nullptr;
    experience = 0;
    inventario = new Item[28]{};
}

Player::Player(const char *name, int health, int x, int y) {
    this->health = health;
    this->x = x;
    this->y = y;
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    experience = 0;
}

Player::~Player() {
    cout<<"Destructor de Player"<<endl;
    delete []name;
    delete []inventario;
}

void Player::move(int dx, int dy, int dz) {
    x += dx;
    y += dy;
    z += dz;
}

void Player::receive_damage(int damage) {
    health -= damage;
    if (health < 0) health = 0;
}

void Player::attack() {

}

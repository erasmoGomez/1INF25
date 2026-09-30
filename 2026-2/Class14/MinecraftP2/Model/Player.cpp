#include "Player.hpp"

Player::Player() {
    x = 10;
    y = 10;
    health = 100;
    name = nullptr;
    experience = 0;
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
    delete []name;
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

const char *Player::get_name() {
    return name;
}

int Player::get_experience() const {
    return experience;
}

int Player::get_health() const {
    return health;
}

int Player::get_x() const {
    return x;
}

int Player::get_y() const {
    return y;
}

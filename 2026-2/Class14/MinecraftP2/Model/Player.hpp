#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "../Utilities/Utils.hpp"
#include "Item.hpp"

class Player{
private:
    char *name;
    int experience;
    int health;
    int x;
    int y;
    int z;
    Item* inventario;
public:
    Player();
    Player(const char *name, int health, int x, int y);
    ~Player();

    void move(int dx, int dy, int dz);
    void receive_damage(int damage);
    void attack();

};

#endif

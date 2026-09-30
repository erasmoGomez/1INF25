#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "../Utilities/Utils.hpp"

class Player{
private:
    char *name;
    int experience;
    int health;
    int x;
    int y;
    int z;

public:
    Player();
    Player(const char *name, int health, int x, int y);
    ~Player();

    void move(int dx, int dy, int dz);
    void receive_damage(int damage);
    void attack();

};

#endif

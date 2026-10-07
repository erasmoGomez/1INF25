#ifndef WORLD_HPP
#define WORLD_HPP
#include "Player.hpp"

class World {
private:
    Player players[10];
    int number_of_players;

public:
    World();
    ~World();

    void load_players(const char *filename);
    void print_players(const char* filename);
};

#endif

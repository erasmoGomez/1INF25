#ifndef WORLD_HPP
#define WORLD_HPP
#include "Player.hpp"
#include "Mob.hpp"
#include "Map.hpp"
class World {
private:
    Player players[10];
    int number_of_players;
    Mob *mobs;
    int number_of_mobs;

    Map map;

public:
    World();
    ~World();

    void load_players(const char *filename);
    void print_players(const char* filename);
    void load_mobs(const char *filename);
    void print_mobs(const char * filename);

    void load_world(const char * filename);
};

#endif

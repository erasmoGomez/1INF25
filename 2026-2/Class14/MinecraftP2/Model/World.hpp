#ifndef WORLD_HPP
#define WORLD_HPP
#include "Player.hpp"
#include "Creeper.hpp"
//#include "Zombie.hpp"

class World {
private:
    Player *player;
    Creeper *creepers;

    int number_of_creepers;
    int number_of_zombies;

public:
    World();
    ~World();

    void load_players(const char *filename);
    void load_creepers(const char *filename);
    void load_zombies(const char *filename);

    Player *get_player();
    Creeper *get_creepers();

    int get_number_of_creepers();
    int get_number_of_zombies();
};

#endif

#ifndef WORLD_HPP
#define WORLD_HPP
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
    void print_players(const char* filename) const;
    void load_mobs(const char *filename);
    void print_mobs(const char * filename) const;

    void load_world(const char * filename);
    void add_elements();
    void display();

    int get_index_player(char selected_player) const;

    void clear_map();

    void re_draw();

    void play();

    void load_items(const char* filename);

    void interact(int);
};

#endif

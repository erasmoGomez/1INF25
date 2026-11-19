#pragma once
#include "Utils.hpp"
#include "MiningStack.hpp"
#include "VillagerQueue.hpp"
#include "WorldGraph.hpp"

class GestorJuego {
private:
    MiningStack mining;
    VillagerQueue villagers;
    WorldGraph world;
    map<string, int> resources;
    string data_dir;
    void execute_option(int option);
    void mine_block();
    void remove_block();
    void add_request();
    void attend_villager();
    void add_region();
    void connect_regions();
    void show_world();
    void collect_resources();
    void craft_sword();
public:
    explicit GestorJuego(const string& data_dir);
    ~GestorJuego();
    void load_data();
    void run();
};

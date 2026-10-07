#include "World.hpp"

World::World() {
    number_of_players = 0;
}

World::~World() {
    cout<<"Se destruyo el mundo!"<<endl;
}

void World::load_players(const char *filename) {
    ifstream input(filename, ios::in);
    //Utils::open_read_file(input, filename);
    while (true) {
        Player p;
        p.read(input);
        if (input.eof()) break;
        players[number_of_players] = p;
        number_of_players++;
    }
}

void World::print_players(const char *filename) {
    ofstream output(filename, ios::out);
    for (int i = 0; i < number_of_players; i++) {
        players[i].print(output);
    }
}



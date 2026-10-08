#include "World.hpp"

World::World() {
    number_of_players = 0;
    number_of_mobs = 0;
    mobs = new Mob[50]{};
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
        //players[number_of_players] = p; //Con la sobrecarga del =
        players[number_of_players].copy(p); //Con el metodo COPY que hace una copia profunda
        number_of_players++;
    }
}

void World::print_players(const char *filename) {
    ofstream output(filename, ios::out);
    for (int i = 0; i < number_of_players; i++) {
        players[i].print(output);
    }
}

void World::load_mobs(const char *filename) {
    ifstream input;
    Utils::open_read_file(input, filename);
    while (true) {
        Mob m;
        input>>m;
        if (input.eof()) break;
        mobs[number_of_mobs].copy(m);
        number_of_mobs++;
    }
}

void World::print_mobs(const char *filename) {
    ofstream output;
    Utils::open_write_file(output, filename);
    for (int i = 0; i < number_of_mobs; i++) {
        output<<mobs[i];
    }
}

void World::load_world(const char *filename) {

}


/*
void operator>>(ifstream &input, class Mob &m); // input>>m // INTERACTUA O DEPENDE DE LA CLASE IFSTREAM :( // SOBRECARGA EXTERNA
void operator=(const Player &other); // p = p2 // INTERACTUA O DEPENDE DE LA CLASE // SOBRECARGA INTERNA
*/

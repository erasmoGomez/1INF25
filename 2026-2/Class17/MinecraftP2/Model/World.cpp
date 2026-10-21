#include "World.hpp"

World::World() {
    number_of_players = 0;
    number_of_mobs = 0;
    mobs = new Mob[50]{};
}

World::~World() {
    // cout<<"Se destruyo el mundo!"<<endl;
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

void World::print_players(const char *filename) const {
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
        input >> m;
        if (input.eof()) break;
        mobs[number_of_mobs].copy(m);
        number_of_mobs++;
    }
}

void World::print_mobs(const char *filename) const {
    ofstream output;
    Utils::open_write_file(output, filename);
    for (int i = 0; i < number_of_mobs; i++) {
        output << mobs[i];
    }
}

void World::load_world(const char *filename) {
    ifstream input;
    Utils::open_read_file(input, filename);
    map.load_map(input);
}

void World::add_elements() {
    for (int i = 0; i < number_of_players; i++)
        map += players[i];
    for (int j = 0; j < number_of_mobs; j++)
        map += mobs[j];
}

void World::display() {
    map.display();
}

int World::get_index_player(char selected_player) const {
    char buffer[20];
    for (int i = 0; i < number_of_players; i++) {
        players[i].get_name(buffer);
        if (buffer[0] == selected_player) return i;
    }
    return -1;
}

void World::clear_map() {
    ifstream input;
    Utils::open_read_file(input, "Data/world.csv");
    map.load_map(input);
}

void World::re_draw() {
    clear_map();
    add_elements();
    display();
}

void World::play() {
    char selected_player;
    char mov;
    while (true) {
        cout << "Ingrese un Player (Primera letra del nombre) o coloque 0 para salir;" << endl;
        cin >> selected_player;
        if (selected_player == '0') break;
        int selected_index = get_index_player(selected_player);
        if (selected_index == -1) {
            cout << "No se encontro el Player" << endl;
            break;
        }
        cout << "Ingrese la direccion hacia donde desea moverse W S D A, para salir 0" << endl;
        while (true) {
            cin >> mov;
            if (players[selected_index].move(mov, map)) {
                //Si me puedo mover
                if (mov == '0') break;
                if (mov == 'W') players[selected_index]++;
                if (mov == 'S') ++players[selected_index];
                if (mov == 'D') players[selected_index]--;
                if (mov == 'A') --players[selected_index];
            } else
                cout << "No m puedo mover a la posicion que pides" << endl;
            re_draw();
        }
    }
}


/*
void operator>>(ifstream &input, class Mob &m); // input>>m // INTERACTUA O DEPENDE DE LA CLASE IFSTREAM :( // SOBRECARGA EXTERNA
void operator=(const Player &other); // p = p2 // INTERACTUA O DEPENDE DE LA CLASE // SOBRECARGA INTERNA
*/

//
// Created by erasmo on 10/7/26.
//

#include "Map.hpp"

#include "Player.hpp"

int Map::get_ancho() const {
    return ancho;
}

void Map::set_ancho(const int ancho) {
    this->ancho = ancho;
}

int Map::get_largo() const {
    return largo;
}

void Map::set_largo(const int largo) {
    this->largo = largo;
}

int Map::get_altura() const {
    return altura;
}

void Map::set_altura(const int altura) {
    this->altura = altura;
}

int Map::get_n_players() const {
    return n_players;
}

void Map::set_n_players(const int n_players) {
    this->n_players = n_players;
}

int Map::get_n_mobs() const {
    return n_mobs;
}

void Map::set_n_mobs(const int n_mobs) {
    this->n_mobs = n_mobs;
}

void Map::load_map(ifstream &input) {
    int contenido;
    for(int i=0; i<largo; i++)
        for(int j = 0; j<ancho; j++){
            input>>contenido;
            bool transitable = contenido == 1;
            Block b(transitable);
            bloques[i*largo + j] = b; // Si la clase tiene punteros, debo crear una copia profunda
            input.get();
        }
}

void Map::display() {
    for(int i = 0; i<largo;i++){
        for(int j=0; j<ancho; j++)
            cout<<bloques[i*largo+j];
        cout<<endl;
    }
}

bool Map::inside(int x, int y) {
    return x>=0 and y>= 0 and x<largo and y < ancho;
}

bool Map::transitable(int x, int y) {
    return bloques[x*largo+y].is_transitable();
}

void Map::operator+=(class Player p) {
    char buffer[20];
    p.get_name(buffer);
    Block b;
    b.set_sprite(buffer[0]);
    bloques[p.get_x()*largo + p.get_y()] = b;
}

void Map::operator+=(class Mob m) const {
    char buffer[20];
    m.get_type(buffer);
    Block b;
    if (strcmp(buffer, "Skeleton") == 0) b.set_sprite('K');
    if (strcmp(buffer, "Spider") == 0) b.set_sprite('#');
    if (strcmp(buffer, "Zombie") == 0) b.set_sprite('Z');
    if (strcmp(buffer, "Creeper") == 0) b.set_sprite('*');
    b.set_transitable(false);
    bloques[m.get_x()*largo + m.get_y()] = b;
}

Map::Map() {
    ancho = 40;
    largo = 40;
    altura = 40;
    n_players = 0;
    n_mobs = 0;
    bloques = new Block[ancho*largo];
}

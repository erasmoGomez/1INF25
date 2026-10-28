//
// Created by erasmo on 10/7/26.
//

#ifndef MINECRAFTP2_MAP_HPP
#define MINECRAFTP2_MAP_HPP
#include "Player.hpp"
#include "Mob.hpp"
#include "Block.hpp"

class Map {
public:
    int get_ancho() const;

    void set_ancho(const int ancho);

    int get_largo() const;

    void set_largo(const int largo);

    int get_altura() const;

    void set_altura(const int altura);

    int get_n_players() const;

    void set_n_players(const int n_players);

    int get_n_mobs() const;

    void set_n_mobs(const int n_mobs);

    void load_map(ifstream &input);

    void display();

    bool inside(int x, int y);

    bool transitable(int x, int y);

    //Sobrecarga de +=
    void operator+=(class Player);
    void operator+=(class Mob) const;

private:
    int ancho;
    int largo;
    int altura;
    int n_players;
    int n_mobs;
    class Block *bloques;

public:
    Map();
};


#endif //MINECRAFTP2_MAP_HPP

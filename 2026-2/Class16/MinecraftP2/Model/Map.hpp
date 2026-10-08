//
// Created by erasmo on 10/7/26.
//

#ifndef MINECRAFTP2_MAP_HPP
#define MINECRAFTP2_MAP_HPP

#include "Block.hpp"
class Map {
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
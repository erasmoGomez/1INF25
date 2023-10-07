/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Map.hpp
 * Author: ASUS
 *
 * Created on October 3, 2023, 9:15 AM
 */

#ifndef MAP_HPP
#define MAP_HPP
#include "tile.hpp"
#include "hero.hpp"
#define MAX_ROWS 20
#define MAX_COLUMNS 20
class Map {
public:
    Map();
    Map(const Map& orig);
    Map(const char*, const class Hero&);
    virtual ~Map();
    //void load_map(const char*, const Hero &h);
    void Draw(ofstream &);
private:
    class Tile mapa[MAX_ROWS][MAX_COLUMNS];
    class Hero heroe;
};

#endif /* MAP_HPP */


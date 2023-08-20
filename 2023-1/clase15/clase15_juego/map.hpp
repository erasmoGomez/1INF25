/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   map.hpp
 * Author: erasmog
 *
 * Created on June 6, 2023, 8:41 AM
 */

#ifndef MAP_HPP
#define MAP_HPP
#include "functions.hpp"
#include "hero.hpp"
#include "tile.hpp"
class Map{
private:
    class Tile map[MAX_ROWS][MAX_COLUMNS];
    int posXHero;
    int posYHero;
public:
    Map();
    Map(const char*, const Hero&);
    void draw(ofstream &);
    void draw_hero(ofstream &, const Hero&);
};

#endif /* MAP_HPP */
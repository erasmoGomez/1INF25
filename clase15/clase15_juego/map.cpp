/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "functions.hpp"
#include "hero.hpp"
#include "tile.hpp"
#include "map.hpp"

Map::Map() {
    posXHero = MAX_ROWS / 2;
    posYHero = MAX_COLUMNS / 2;
    for (int i = 0; i < MAX_ROWS; i++)
        for (int j = 0; j < MAX_COLUMNS; j++) {
            class Tile t('X', i, j);
            map[i][j] = t;
        }
}

Map::Map(const char* filename, const Hero &h) {
    posXHero = h.GetPosX();
    posYHero = h.GetPosY();
    ifstream input(filename, ios::in);
    char tile_char;
    for (int i = 0; i < MAX_ROWS; i++)
        for (int j = 0; j < MAX_COLUMNS; j++) {
            input>>tile_char;
            class Tile t(tile_char, i, j);
            map[i][j] = t;
        }
}

void Map::draw(ofstream & arch){
    for (int i = 0; i< MAX_ROWS; i++){
        for(int j=0; j< MAX_COLUMNS; j++){
            map[i][j].Display(arch);
        }
        arch<<endl;
    }
}

void Map::draw_hero(ofstream &arch, const Hero &h){
    class Tile t(h.GetTileChar(), h.GetPosX(), h.GetPosY());
    map[h.GetPosX()][h.GetPosY()] = t;
    for (int i = 0; i< MAX_ROWS; i++){
        for(int j=0; j< MAX_COLUMNS; j++){
            map[i][j].Display(arch);
        }
        arch<<endl;
    }
    posXHero = h.GetPosX();
    posYHero = h.GetPosY();
}

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Map.cpp
 * Author: ASUS
 * 
 * Created on October 3, 2023, 9:15 AM
 */

#include "Map.hpp"

Map::Map() {
}

Map::Map(const Map& orig) {
}

Map::Map(const char* file_name, const Hero &h) {
    ifstream input(file_name, ios::in);
    char c;
    for(int i=0; i<MAX_ROWS; i++)
        for(int j=0; j<MAX_COLUMNS; j++){
            input>>c;
            class Tile t(c, i, j);
            mapa[i][j] = t;
        }
    
    class Hero h1;
    char buffer[100];
    h.GetName(buffer);
    h1.SetName(buffer);
    h1.SetHp(h.GetHp());
    h1.SetAttack(h.GetAttack());
    h1.SetPosx(h.GetPosx());
    h1.SetPosy(h.GetPosy());
    this->heroe = h1;
}

Map::~Map() {
}

void Map::Draw(ofstream &out){
    mapa[heroe.GetPosx()][heroe.GetPosy()].SetContent('H');
    for(int i=0; i<MAX_ROWS; i++){
        for(int j=0; j<MAX_COLUMNS; j++)
            mapa[i][j].Display(out);
        out<<endl;
    }
    
}


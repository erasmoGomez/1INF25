/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <valarray>

#include "tile.hpp"
#include "hero.hpp"

Tile::Tile(){
    this->content = 'o';
}

Tile::Tile(const char c, int x, int y){
    this->content = c;
    this->x = x;
    this->y = y;
}

int Tile::GetY() const {
    return y;
}

int Tile::GetX() const {
    return x;
}

char Tile::GetContent() const {
    return content;
}

void Tile::SetY(int y) {
    this->y = y;
}

void Tile::SetX(int x) {
    this->x = x;
}

void Tile::SetContent(char content) {
    this->content = content;
}

void Tile::Display(ofstream &out){
    out<< setw(1) << '|' << this->content<<setw(1)<< '|';
}
        
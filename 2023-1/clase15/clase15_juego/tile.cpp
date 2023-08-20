/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "tile.hpp"

Tile::Tile() {
    content = 'X';
}

Tile::Tile(char c, int x, int y) {
    content = c;
    this->x = x;
    this->y = y;
}

void Tile::SetY(int y) {
    this->y = y;
}

int Tile::GetY() const {
    return y;
}

void Tile::SetX(int x) {
    this->x = x;
}

int Tile::GetX() const {
    return x;
}

void Tile::SetContent(char content) {
    this->content = content;
}

char Tile::GetContent() const {
    return content;
}

void Tile::Display(ofstream & arch) {
    arch << setw(1) << '|' << this->content << setw(1) << '|';
}

void Tile::operator+(Tile t) {
    cout << setw(1) << '|' << this->content << "  " << t.GetContent() << setw(1) << '|';
}

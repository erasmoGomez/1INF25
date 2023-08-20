/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "functions.hpp"
#include "tile.hpp"

Tile::Tile() {
    content = 'L';
    x = 0;
    y = 0;
}

Tile::Tile(char content, int x, int y) {
    this->content = content;
    this->x = x;
    this->y = y;
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

int Tile::GetY() const {
    return this->y;
}

int Tile::GetX() const {
    return this->x;
}

char Tile::GetContent() const {
    return this->content;
}

void Tile::draw(ofstream &arch) {
    //cout<<setw(4)<<setfill('-')<<' '<<endl;
    arch << setw(1) << '|' << this->content << setw(1) << '|';
    //cout<<setw(4)<<setfill('-')<<' ';
    //setfill(' ');
}

void Tile::operator+(Tile t) {
    cout << setw(1) << '|' << this->content << "  " << t.GetContent() << setw(1) << '|';
}



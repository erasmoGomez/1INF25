/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   tile.hpp
 * Author: ASUS
 *
 * Created on October 3, 2023, 9:05 AM
 */

#ifndef TILE_HPP
#define TILE_HPP
#include <fstream>
using namespace std;
class Tile{
private:
    char content;
    int x;
    int y;
public:
    Tile();
    Tile(const char, int, int);
    int GetY() const;
    int GetX() const;
    char GetContent() const;
    void SetY(int y);
    void SetX(int x);
    void SetContent(char content);
    void Display(ofstream &);
};

#endif /* TILE_HPP */


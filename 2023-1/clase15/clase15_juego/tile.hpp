/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   tile.hpp
 * Author: erasmog
 *
 * Created on June 6, 2023, 7:23 AM
 */

#ifndef TILE_HPP
#define TILE_HPP
#include "functions.hpp"

class Tile{
private:
    char content;
    int x;
    int y;
public:
    Tile(); //Constructor por Defecto
    Tile(char, int = MAX_ROWS/2, int = MAX_COLUMNS/2);
    void SetY(int y);
    int GetY() const;
    void SetX(int x);
    int GetX() const;
    void SetContent(char content);
    char GetContent() const; 
    void Display(ofstream &);
    void operator+(const class Tile);
};

#endif /* TILE_HPP */


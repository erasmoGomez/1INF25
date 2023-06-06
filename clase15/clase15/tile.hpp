/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   tile.hpp
 * Author: erasmog
 *
 * Created on June 6, 2023, 2:22 AM
 */

#ifndef TILE_HPP
#define TILE_HPP
class Tile {
private:
    char content;
    int x;
    int y;
public:
    Tile();
    Tile(char, int = 0, int = 0);
    void SetY(int y);
    void SetX(int x);
    void SetContent(char content);
    int GetX() const;
    int GetY() const;
    char GetContent() const;
    void operator +(const class Tile);
    void draw(ofstream &);
};


#endif /* TILE_HPP */


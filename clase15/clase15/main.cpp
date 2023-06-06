/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: erasmog
 *
 * Created on May 31, 2023, 8:54 AM
 */

#include "functions.hpp"
#include "tile.hpp"
#include "map.hpp"
#include "hero.hpp"

/*
 * 
 */
int main(int argc, char** argv) {
    ofstream arch("out.txt", ios::out);
    class Tile tA, tB;
    tA.SetContent('A');
    arch<<tA.GetContent()<<endl;
    tA.draw(arch);
    tB.SetContent('B');
    tB.draw(arch);
    arch<<endl;
    tA + tB;
    
    class Hero h("Erasmo", 'E',100);
    
    arch<<h;
    
    h.move(5,8);
    arch<<h;
    
    arch<<endl;
    
    class Map map;
    map.draw(arch);
    
    arch<<endl;
    class Map map2("map.txt", h);
    map2.draw_hero(arch, h);
    arch<<h;
    
    
    return 0;
}


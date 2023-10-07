/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Erasmo G. Montoya
 *
 * Created on September 27, 2023, 7:54 AM
 */
#include <iostream>
#include <iomanip>
#include <cstring>
#include "hero.hpp"
#include "tile.hpp"
#include "Map.hpp"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    class Hero ash;
    ash.SetHp(5000);
    int hp_ash = ash.GetHp();
    //cout<<hp_ash<<endl;
    
    char nombre[500];
    
    ash.SetName("Ash Ketchup");
    ash.GetName(nombre);
    //cout<<nombre<<endl;
    
    class Hero h1;
    h1.SetName("Teemo");
    h1.SetAttack(560.35);
    h1.SetHp(45);
    h1.SetPosx(3);
    h1.SetPosy(50);
    //h1.Display();   

    //ash.Display();
    
    ofstream out("heroes.txt", ios::out);
//    out<<h1;
    
//    h1.SetPosx(100);
//    h1.SetPosy(100);
//    h1++;
//    out<<h1;
//    ++h1;
//    out<<h1;
//    h1--;
//    out<<h1;
//    --h1;
//    out<<h1;
    
    class Tile t;
    t.SetContent('X');
    //t.Display(out);
    h1.SetPosx(10);
    h1.SetPosy(10);
    class Map mapita("mapa.txt", h1);
    mapita.Draw(out);
    return 0;
}


/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: erasmog
 *
 * Created on June 6, 2023, 6:53 AM
 */

#include "functions.hpp"
#include "tile.hpp"
#include "hero.hpp"
#include "map.hpp"

/*
 * 
 */
int main(int argc, char** argv) {
    ofstream arch("out.txt", ios::out);
    class Tile t; //LLamada al constructor por defecto
    cout<< t.GetContent()<<endl;
    
    class Tile t2('O', 5, 8); //Constructor con parametros
    cout<< t2.GetContent()<<endl;
    
    class Tile t3('E'); //Constructor con parametros
    cout<< t3.GetContent()<<endl;
    
    t.Display(arch);
    t2.Display(arch);
    t3.Display(arch);
    
    //sobrecarga operator interno
    t + t3;
    class Hero h("Erasmo Montoya");
    arch<<endl;
    //sobrecarga operator externo
    arch<<h;
    
    class Map m;
    arch<<endl;
    m.draw(arch);
    
    class Map m2("map.txt", h);
    arch<<endl;
    m2.draw(arch);
    
    class Map m3("map.txt", h);
    arch<<endl;
    m3.draw_hero(arch,h);
    arch<<endl;
    //Comienza el juego
    h.Move(7,5);
    arch<<h;
    h.Move(2, 'R');
    m3.draw_hero(arch,h);
    arch<<endl;
    h.Move(5, 'D');
    m3.draw_hero(arch,h);
    arch<<endl;
    h.Move(1, 'I');
    m3.draw_hero(arch,h);
    arch<<endl;
    h.Move(7, 'U');
    m3.draw_hero(arch,h);
    arch<<endl;
    return 0;
}


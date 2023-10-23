/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Game.hpp
 * Author: ASUS
 *
 * Created on October 18, 2023, 7:40 AM
 */

#ifndef GAME_HPP
#define GAME_HPP
#include "Hero.hpp"
#include "Item.hpp"
#include "utils.hpp"
using namespace std;
class Game {
public:
    Game();
    Game(const Game& orig);
    virtual ~Game();
    void cargar();
    void mostrar();
    void actualizar();
    void carga_heroes(ifstream &);
    void carga_items(ifstream &);
    void mostrar_heroes();
    void mostrar_items();
private:
    class Hero heroes[5];
    class Item items[50];
    int n_heroes;
    int n_items;

};

#endif /* GAME_HPP */


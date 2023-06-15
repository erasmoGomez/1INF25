/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: erasmog
 *
 * Created on June 14, 2023, 6:15 AM
 */

#include "functions.hpp"
#include"item.hpp"
#include "pokeball.hpp"
#include "consumable.hpp"
#include "backpack.hpp"
/*
 * 
 */
int main(int argc, char** argv) {
    //Pokeball masterball_falsa(123, "Master Pokeball", "Catch them all", 100);
//    Pokeball masterball(123, "Master Pokeball", "Catch them all", 100);
//    Consumable zinc;
    
    Backpack backpack;
    backpack.load_backpack();
//    backpack.mostrar_pokeballs_pos(0);
//    backpack.mostrar_consumables_pos(10);
//    backpack.mostrar_consumables_pos(12);
    backpack.mostrar_pokeballs();
    backpack.mostrar_consumables();
    
    //load_backpack(backpack, 'items2.csv');
    
//    Backpack backpack;
//    backpack.load_backpck('items2.csv'); //dentro de la clase
            
    return 0;
}


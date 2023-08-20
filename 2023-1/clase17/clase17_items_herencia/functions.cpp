/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "functions.hpp"
//#include "backpack.hpp"

void load_backpack(Backpack &backpack, const char * filename){
    ifstream arch(filename, ios::in);
    int type = 0;
    int indice_pokeballs = 0, indice_consumables = 0;
    char buffer[200];
    while(1){
        arch>>type;
        if(arch.eof()) break;
        if(type == 1) {
            //arch>>backpack.cargar_pokeballs(indice_pokeballs);
            indice_pokeballs++;
        }
        if(type == 2 or type == 3 or type == 4){
            //arch>>backpack.cargar_consumables(indice_consumables);
            indice_consumables++;
        }
        if(type == 5 or type == 6){
            arch.getline(buffer, 200, '\n');
        }
    }
    
}

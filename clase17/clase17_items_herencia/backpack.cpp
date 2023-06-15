/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "functions.hpp"
#include "backpack.hpp"

Backpack::Backpack() {

}

void Backpack::load_backpack() {
    ifstream arch("items3.csv", ios::in);
    int type = 0, indice_pokeballs = 0, indice_consumables = 0;
    char buffer[500];
    int id;
    char name[20], desc[200];
    double catch_ratio;
    int variacion;
    while (1) {
        //Si el topo es 1 es pokeball
        //Si el tipo es 2 3 4 es consumable
        //Si el tipo es 5 y 6 era objeto simple
        arch>>type;
        if (arch.eof()) break;
        //cout<<"TIPO : > "<<type<<endl;
        arch.get();
        arch>>id;
        arch.get();
        arch.getline(name, 20, ',');
        arch.getline(desc, 200, ',');
        if (type == 1) {
            arch>>catch_ratio;
            arch.get();
            //arch>>pokeballs[indice_pokeballs]
//            cout<<"TIPO1"<<endl;
//            cout<<name<<endl;
//            cout<<desc<<endl;
//            cout<<catch_ratio<<endl;
//            cout<<indice_pokeballs<<endl;
            pokeballs[indice_pokeballs].load_pokeball(id, name, desc, catch_ratio);
            indice_pokeballs++;
        } else {
            if (type == 2 or type == 3 or type == 4) {
                arch>>variacion;
                arch.get();
                //cout<<"Tipo 234"<<endl;
                consumables[indice_consumables].load_consumable(id, name, desc, variacion);
                indice_consumables++;
            } else {
                //cout<<"NO LEE"<<endl;
                arch.getline(buffer, 500, '\n');
            }
        }
    }
}

void Backpack::mostrar_pokeballs_pos(int indice){
    pokeballs[indice].print_pokeball();
}

void Backpack::mostrar_consumables_pos(int indice){
    consumables[indice].print_consumable();
}

void Backpack::mostrar_pokeballs(){
    int indice = 0;
    while(1){
        if(pokeballs[indice].GetID()==0) break;
        mostrar_pokeballs_pos(indice);
        indice++;
    }
}

void Backpack::mostrar_consumables(){
    int indice = 0;
    while(1){
        if(consumables[indice].GetID()==0) break;
        mostrar_consumables_pos(indice);
        indice++;
    }
}
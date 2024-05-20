/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "Utils.hpp"
#include "Juego.hpp"
using namespace std;

Juego::Juego(){
    n_heroes = 0;
}
void Juego::carga_mapa(){
    ifstream input_mapa("map_dataset.csv", ios::in);
    mapa.leer(input_mapa);
    
}

void Juego::cargar_juego(){
    carga_mapa();
    carga_heroes();
}

void Juego::mostrar_mapa(){
    mapa.mostrar();
}

void Juego::carga_heroes(){
    ifstream input_heroes("heroes_dataset.csv", ios::in);
    while(true){
        //heroes[n_heroes].leer(input_heroes);
        input_heroes>>heroes[n_heroes];
        if(input_heroes.eof())break;
        n_heroes++;
    }
    
}

void Juego::colocar_heroes(){
    for(int i=0;i<n_heroes;i++)
        mapa+=heroes[i];
}
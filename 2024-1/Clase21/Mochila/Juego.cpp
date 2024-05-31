/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Juego.cpp
 * Author: Erasmo G. Montoya
 * 
 * Created on May 27, 2024, 5:58 PM
 */
#include "Utils.hpp"
#include "Juego.hpp"
using namespace std;

Juego::Juego() {
}

Juego::Juego(const Juego& orig) {
}

Juego::~Juego() {
}

void Juego::carga_items() {
    ifstream input("items.csv", ios::in);
    char tipo[20], c;
    int n_heroe;
    //Weapon,3,Sword,A sharp and sturdy sword.,147
    //JUEGO - ITEM - CONSUMIBLE/ARMADURA/ARMA
    while(true){
        input.getline(tipo, 20, ',');
        if(input.eof())break;
        input>>n_heroe>>c;
        heroes[n_heroe-1].agregar_mochila(input, tipo);
    }
}

void Juego::jugar() {
    int indice_heroe = 3;
    char nombre_item[20]="Sword";
    heroes[indice_heroe-1].equipar(nombre_item, "Weapon");
    //heroes[indice_heroe-1].mostrar();
}

void Juego::mostrar_datos(){
    int indice_heroe = 3;
    ofstream output("reporte.txt",ios::out);
    heroes[indice_heroe-1].mostrar(output);
}
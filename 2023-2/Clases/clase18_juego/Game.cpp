/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Game.cpp
 * Author: ASUS
 * 
 * Created on October 18, 2023, 7:40 AM
 */

#include "Game.hpp"
using namespace std;

Game::Game() {
    n_items = 0;
    n_heroes = 0;
}

Game::Game(const Game& orig) {
}

Game::~Game() {
}

void Game::carga_heroes(ifstream &input) {
    int n_datos = 0;
    while (1) {
        input >> heroes[n_datos];
        if (input.eof())break;
        n_datos++;
    }
    this->n_heroes = n_datos+1;
}

void Game::carga_items(ifstream &input) {
    int n_datos = 0;
    while (1) {
        input >> items[n_datos];
        if (input.eof())break;
        n_datos++;
    }
    this->n_items = n_datos+1;
}

void Game::cargar() {
    ifstream input_heroes("heroes.csv", ios::in);
    ifstream input_items("items.csv", ios::in);
    carga_heroes(input_heroes);
    carga_items(input_items);
}

void Game::mostrar_heroes() {
    ofstream output_heroes("reporte_heroes.txt", ios::out);
    imprime_headers(output_heroes, "DETAILED INFORMATION PER HERO", "heroes");
    for(int i=0;i<n_heroes;i++)
        output_heroes<<heroes[i];
}


void Game::mostrar_items() {
    ofstream output_items("reporte_items.txt", ios::out);
    imprime_headers(output_items, "DETAILED INFORMATION PER ITEM", "items");
    for(int i=0;i<n_items;i++)
        output_items<<items[i];
}

void Game::mostrar_actualizado() {
    ofstream output_items("reporte_heroes_items.txt", ios::out);
    imprime_headers(output_items, "DETAILED INFORMATION PER HERO", "heroes");
    for(int i=0;i<n_heroes;i++)
        output_items<<heroes[i];
}

void Game::mostrar() {
    mostrar_heroes();
    mostrar_items();
}

void Game::actualizar() {
    int index_hero = 0;
    for(int i = 0; i<n_items; i++){
        index_hero = items[i].GetCodigo_hero();
        heroes[index_hero-1] += items[i];
    }
}


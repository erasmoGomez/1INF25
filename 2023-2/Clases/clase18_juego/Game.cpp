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
    this->n_heroes = n_datos;
}

void Game::cargar() {
    ifstream input_heroes("heroes.csv", ios::in);
    ifstream input_items("items.csv", ios::in);
    carga_heroes(input_heroes);
}

void Game::mostrar_heroes() {
    ofstream output_heroes("reporte_heroes.txt", ios::out);
    imprime_headers(output_heroes);
    for(int i=0;i<n_heroes;i++)
        output_heroes<<heroes[i];
}

void Game::mostrar() {
    mostrar_heroes();
}

void Game::actualizar() {

}


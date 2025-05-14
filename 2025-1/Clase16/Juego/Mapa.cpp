/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Mapa.cpp
 * Author: hecto
 * 
 * Created on May 7, 2025, 5:20 PM
 */

#include "Mapa.hpp"
#include "Heroe.hpp"

Mapa::Mapa() {
    ancho = 0;
    alto = 0;
    casillas = nullptr;
}

Mapa::Mapa(int ancho, int alto){
    this->alto = alto;
    this->ancho = ancho;
    this->casillas = new Casilla[this->ancho*this->alto];
}

Mapa::Mapa(const Mapa& orig) {
}

Mapa::~Mapa() {
}


void Mapa::cargar_mapa(ifstream &input){
    int contenido_mapa;
    input>>ancho;
    input.get();
    input>>alto;
    casillas = new Casilla[ancho*alto]{};
    for(int i=0; i<alto; i++)
        for(int j=0; j<ancho; j++){
            input>>contenido_mapa;
            bool transitable = contenido_mapa == 1;
            Casilla c(transitable);
            casillas[j*ancho+i] = c;
            input.get();
        }
}

void Mapa::mostrar_mapa(){
    for(int i=0; i<alto; i++){
        for(int j=0; j<ancho; j++){
            cout<<casillas[j*ancho+i];
        }
        cout<<endl;
    }
}

bool Mapa::es_transitable(int x, int y){
    return casillas[y*ancho+x].isTransitable();
}

bool Mapa::dentro(int x, int y) const{
    return x>=0 and y>= 0 and x<ancho and y<alto;
}

void Mapa::operator+=(class Heroe h){
    char buffer[20];
    h.getNombre(buffer);
    Casilla c;
    c.setSprite(buffer[0]);
    casillas[h.getPosY()*ancho+h.getPosX()] = c;
}
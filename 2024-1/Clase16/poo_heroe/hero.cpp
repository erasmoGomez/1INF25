/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <iostream>
#include <cstring>
#include <iomanip>
#include "hero.hpp"

using namespace std;

void Heroe::crear_heroe(){
    hp = 5000;
    posx = 100;
    posy = 200;
    char buffer[20]="Annie";
    nombre = new char[strlen(buffer+1)];
    strcpy(nombre,buffer);
    mana = 55.6;
}

void Heroe::mostrar(){
    cout<<"Heroe: "<<nombre<<endl;
    cout<<"HP: "<<hp<<setw(10)<<"Mana: "<<mana<<endl;
    cout<<"X: "<<posx<<setw(5)<<"Y: "<<posy<<endl;
}

void Heroe::curar(int cura){
    //hp = hp + cura;
    hp+=cura;
}

void Heroe::mover(int x, int y, double m){
    posx += x;
    posy += y;
    mana -= m;
}
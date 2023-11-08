/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Erasmo G. Montoya
 *
 * Created on November 7, 2023, 12:39 AM
 */

#include "Arbol.hpp"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    class Arbol equipo;
    equipo.crear("heroes.csv");
    equipo.en_orden();
    class Hero heroe;
    heroe = equipo.buscar("Ash");
    if(heroe.GetCode()!=-1)
        cout<<"Dato buscado: "<<heroe<<endl;
    else
        cout<<"NO se encontro"<<endl;
    return 0;
}


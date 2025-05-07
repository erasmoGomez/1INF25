/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Erasmo Gomez
 * Description: 
 * Created on May 6, 2025, 5:47 PM
 */
#include "Heroe.hpp"

/*
 * 
 */
int main(int argc, char** argv) {
//    class Heroe h;
//    Heroe h2;
//    class Heroe h3(200, 35.5, 100.33);
//    class Heroe h;
    ofstream output("reporte.txt", ios::out);
    ifstream input("heroes.csv", ios::in);
//    h.cargar_info(input);
//    h.mostrar_info(output);
    
    class Heroe heroes[10];
    int cantidad_heroes = 0;
    while(true){
        class Heroe h;
        h.cargar_info(input);
        if(input.eof())break;
        heroes[cantidad_heroes] = h;
        cantidad_heroes++;
    }
    cout<<cantidad_heroes<<endl;
    for(int i = 0; i< cantidad_heroes; i++)
        heroes[i].mostrar_info(output);
    return 0;
}


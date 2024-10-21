/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Erasmo G. Montoya
 *
 * Created on October 7, 2024, 5:36 PM
 */

#include "Heroe.hpp"

/*
 * 
 */
int main(int argc, char** argv) {
    Heroe h1;
    h1.crear();
    h1.mostrar();
    Heroe h2("Miguel Guanira", 10000);
    h2.mostrar();
    
    h1.mover(8,2);
    h1.curar(40);
    h1.mostrar();
    
    char nombre[50]{};
    h1.setNombre("Rony Cueva");
    h1.getNombre(nombre);
    h1.setMana(75);
    cout<<nombre<<"   "<<h1.getMana()<<endl;
    return 0;
}


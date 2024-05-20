/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Erasmo G. Montoya
 *
 * Created on April 30, 2024, 9:07 PM
 */
#include <iostream>
#include <cstring>
#include <iomanip>
#include "hero.hpp"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
//    class Heroe h1;
//    h1.crear();
//    h1.mostrar();
//    h1.curar(500);
//    h1.mostrar();
//    h1.mover(50, -75, 33.5);
//    h1.mostrar();
//    h1.setHp(10);
//    h1.mostrar();
//    int hp_h1 = h1.getHp();
//    cout<<"HP get: "<< h1.getHp()<<endl;
//    
//    h1.setNombre("Erasmo");
//    char* nombre;
//    h1.getNombre(nombre);
//    cout<<nombre<<endl;
//    class Heroe h2;
//    h2.mostrar();
    
    Heroe h3;
    cout<<h3.getHp()<<endl;
    Heroe h4("Miguel Guanira", 9000);
    h4.mostrar();
    
    char nombre[20];
    h4.setNombre("Rony Cueva");
    h4.getNombre(nombre);
    cout<<nombre<<endl;
    
    class Heroe h5; //Aqui llamo automaticamente al constructor por defecto.
    cout<<h5.getHp()<<endl;
    
    class Heroe h6("Tone", 100);
    h6.mostrar();

    return 0;
}


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
#include "hero.hpp"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    class Heroe annie;
    annie.crear_heroe();
    annie.mostrar();
    annie.curar(200);
    annie.mostrar();
    //annie.hp+=200; no se puede hacer x q no se tiene acceso al atributo privado HP
    annie.mover(100, -50, 3.5);
    annie.mostrar();
    
//    class Heroe teemo;
//    teemo.crear_heroe();
//    teemo.mostrar();
    return 0;
}


/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Erasmo G. Montoya
 *
 * Created on October 28, 2024, 5:39 PM
 */

#include "Personaje.hpp"
#include "Guerrero.hpp"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
//    Personaje p;
//    p.realizarAccion();
    Guerrero g;
    g.realizarAccion();
    
    Personaje *ptr_p;
    //ptr_p->realizarAccion()
    
    ptr_p = &g;
    ptr_p->realizarAccion();
    ptr_p->realizarAccionPura();
    return 0;
}


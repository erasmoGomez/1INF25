/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Erasmo G. Montoya
 *
 * Created on November 7, 2023, 12:37 AM
 */

#include "Plantilla.hpp"
#include "Hero.hpp"

/*
 * 
 */
int main(int argc, char** argv) {
//    class Plantilla<int> plantilla_int;
//    plantilla_int.SetDato(13);
//    plantilla_int.imprimir_dato();
    class Hero h;
    h.SetCode(100);
    h.SetAtt(200.5);
    h.SetName("Erasmo");
    class Plantilla<Hero> plantilla_hero;
    plantilla_hero.SetDato(h);
    plantilla_hero.imprimir_dato();
    class Hero h2;
    h2 = plantilla_hero.GetDato();
    cout<<h2<<endl;
    return 0;
}


//
// Created by Erasmo on 26/09/25.
//

#include "Juego.hpp"

Juego::Juego() {
    cantidad_heroes = 0;
}

void Juego::cargar_heroes() {
    ifstream input("Data/heroes.csv", ios::in);

    while (true) {
        class Heroe h;
        input>>h;
        if (input.eof())break;
        heroes[cantidad_heroes] = h;
        cantidad_heroes++;
    }
}

void Juego::mostrar_heroes() {
    ofstream output("Reports/reporte_heroes_juego.txt", ios::out);
    for(int i=0; i<cantidad_heroes; i++)
        output<<heroes[i];
}

void Juego::cargar_mapa() {
    ifstream input("Data/mapa_grande.csv", ios::in);
    mapa.cargar_mapa(input);
}

void Juego::mostrar_mapa() {
    mapa.mostrar_mapa();
}

void Juego::colocar_heroes() {
    for(int i = 0; i<cantidad_heroes; i++)
        mapa += heroes[i];
}

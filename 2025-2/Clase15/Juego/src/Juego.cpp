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
        h.cargar_datos(input);
        if (input.eof())break;
        heroes[cantidad_heroes] = h;
        cantidad_heroes++;
    }
}

void Juego::mostrar_heroes() {
    ofstream output("Reports/reporte_heroes_juego.txt", ios::out);
    for(int i=0; i<cantidad_heroes; i++)
        heroes[i].mostrar_info(output);
}

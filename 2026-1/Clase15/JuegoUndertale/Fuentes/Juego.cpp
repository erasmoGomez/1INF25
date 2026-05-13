//
// Created by erasmo on 5/12/26.
//

#include "Juego.hpp"

Juego::Juego() {
    cantidad_personajes = 0;
    //codigos = nullptr;
    //codigos = new int[20];
}


void Juego::cargar_personajes(const char *nombre_archivo) {
    ifstream input(nombre_archivo, ios::in);
    Personaje p;
    while (true) {
        // Leer Personaje
        input>>p;
        // Validar EOF
        if (input.eof()) break;
        // Insertar Personaje
        personajes[cantidad_personajes] = p;
        //personajes+=p;
        cantidad_personajes++;
    }
}

void Juego::imprimir_personajes(const char *nombre_archivo) {
    ofstream output(nombre_archivo, ios::out);
    for (int i = 0; i < cantidad_personajes; i++) {
        output << personajes[i];
    }
}

void Juego::jugar() {

}



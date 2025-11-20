//
// Created by Erasmo on 19/11/25.
//

#include "GestorRussianRoulette.hpp"

void GestorRussianRoulette::cargar_jugadores(const char *file_name) {
    ifstream input;
    input.open(file_name, ios::in);
    char tipo;
    while (true) {
        input >> tipo;
        if (input.eof())break;
        input.get();
        ruleta.leer(tipo, input);
    }
}

void GestorRussianRoulette::imrprimir_jugadores(const char *file_name) {
    ofstream output;
    output.open(file_name, ios::out);
    ruleta.imprimir_jugadores(output);
}

void GestorRussianRoulette::jugar(const char* file_name) {
    ofstream output;
    output.open(file_name, ios::out);
    ruleta.jugar(output);
}

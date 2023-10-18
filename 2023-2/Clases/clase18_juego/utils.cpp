/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "utils.hpp"

void imprime_headers(ofstream &output_heroes) {
    char title[100]{"DETAILED INFORMATION PER HERO"};
    int padding = (COLUMN_SIZE * N_COLUMNS - strlen(title)) / 2;
    output_heroes << setw(padding + strlen(title))<<right<< title<<endl;
    imprime_linea(output_heroes);
    output_heroes << left << setw(COLUMN_SIZE) << "ID";
    output_heroes << left << setw(COLUMN_SIZE) << "Name";
    output_heroes << left << setw(COLUMN_SIZE) << "HP";
    output_heroes << right << setw(COLUMN_SIZE) << "ATT" << endl;
    imprime_linea(output_heroes);
}

void imprime_linea(ofstream &output_heroes) {
    for (int i = 0; i < N_COLUMNS * COLUMN_SIZE; i++) {
        output_heroes << "=";
    }
    output_heroes << endl;
}
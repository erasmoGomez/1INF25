/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "utils.hpp"

void imprime_headers(ofstream &output_heroes, const char* _title, const char* type) {
    char title[100];
    strcpy(title, _title);
    int padding;
    if (!strcmp(type, "heroes")){
        padding= (COLUMN_SIZE * N_COLUMNS - strlen(title)) / 2;
        output_heroes << setw(padding + strlen(title))<<right<< title<<endl;
        imprime_linea(output_heroes, N_COLUMNS*COLUMN_SIZE);
        output_heroes << left << setw(COLUMN_SIZE) << "ID";
        output_heroes << left << setw(COLUMN_SIZE) << "Name";
        output_heroes << left << setw(COLUMN_SIZE) << "HP";
        output_heroes << right << setw(COLUMN_SIZE) << "ATT" << endl;
        imprime_linea(output_heroes, N_COLUMNS*COLUMN_SIZE);
    }
    if (!strcmp(type, "items")){
        padding= (10 * COLUMN_SIZE - strlen(title)) / 2;
        output_heroes << setw(padding + strlen(title))<<right<<title<<endl;
        imprime_linea(output_heroes, 10*COLUMN_SIZE);
        output_heroes << left << setw(COLUMN_SIZE) << "ID";
        output_heroes << left << setw(3*COLUMN_SIZE) << "Name";
        output_heroes << left << setw(5*COLUMN_SIZE) << "Description";
        output_heroes << right << setw(COLUMN_SIZE) << "Value" << endl;
        imprime_linea(output_heroes, 10*COLUMN_SIZE);
    }
    
}

void imprime_linea(ofstream &output_heroes, int n) {
    for (int i = 0; i < n; i++) {
        output_heroes << "=";
    }
    output_heroes << endl;
}
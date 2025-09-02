//
// Created by Erasmo on 2/09/25.
//

#include "AuciliaryFunctions.hpp"

void open_file_read(ifstream &input, const char *nombre_archivo) {
    input.open(nombre_archivo, ios::in);
    if (!input.is_open()) {
        cout << "El archivo no se pudo abrir: " << nombre_archivo << endl;
        exit(1);
    }
}

void open_file_write(ofstream &input, const char *nombre_archivo) {
    input.open(nombre_archivo, ios::in);
    if (!input.is_open()) {
        cout << "El archivo no se pudo abrir: " << nombre_archivo << endl;
        exit(1);
    }
}

int read_int(ifstream &input) {
    int i;
    input >> i;
    return i;
}

double read_double(ifstream &input) {
    double d;
    input >> d;
    return d;
}

char *read_str(ifstream &in) {
    char *str;
    char buffer[100];
    in.getline(buffer, 100);
    str = new char[strlen(buffer) + 1]{};
    strcpy(str, buffer);
    return str;
}

int lookup_int(int to_look, int *source){
    for(int i=0; source[i];i++)
        if(source[i] == to_look) return i;
    return -1;
}
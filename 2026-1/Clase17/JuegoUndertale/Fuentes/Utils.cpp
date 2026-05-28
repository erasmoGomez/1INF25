//
// Created by erasmo on 5/13/26.
//

#include "Utils.hpp"

void Utils::apertura_archivo_lectura(ifstream & input, const char * nombre_archivo) {
    input.open(nombre_archivo, ios::in);
    if (not input.is_open()) {
        cout<<"El archivo: "<<nombre_archivo<<" No se puede abrir!"<<endl;
        exit(1);
    }
}

void Utils::apertura_archivo_escritura(ofstream & output, const char *nombre_archivo) {
    output.open(nombre_archivo, ios::in);
    if (not output.is_open()) {
        cout<<"El archivo: "<<nombre_archivo<<" No se puede abrir!"<<endl;
        exit(1);
    }
}

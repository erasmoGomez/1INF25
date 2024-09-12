/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "funciones.hpp"

char* leer_cadena(ifstream &input, int n, char delimitador) {
    char* cadena, buffer[n];
    input.getline(buffer, n, delimitador);
    //if(input.eof()) return nullptr;
    cadena = new char[strlen(buffer) + 1];
    strcpy(cadena, buffer);
    return cadena;
}

void lectura_productos(char***& productos, int*& stocks, double*& precios, 
                       const char*nombre_archivo){
    ifstream input(nombre_archivo, ios::in);
    char** buffer_productos[200]{}, coma;
    int buffer_stocks[200]{}, cantidad=0;
    double buffer_precios[200]{};
    //QHC-492,Terma Solucion,1907.23,17
    while(true){
        buffer_productos[cantidad] = lee_productos(input);
        if(input.eof()) break;
        input>>buffer_precios[cantidad]>>coma>>buffer_stocks[cantidad];
        input.get();
        cantidad++;
    }
    actualizar_productos(productos, stocks, precios,buffer_productos, 
                         buffer_stocks, buffer_precios, cantidad);
}


void actualizar_productos(char***&productos, int*& stocks, double*&precios,
                          char*** buffer_productos, int* buffer_stocks, double* buffer_precios, 
                          int cantidad){
    productos =  new char**[cantidad+1]{};
    stocks = new int[cantidad];
    precios = new double[cantidad];
    for(int i = 0; i<cantidad;i++){
        productos[i] = buffer_productos[i];
        stocks[i] = buffer_stocks[i];
        precios[i] = buffer_precios[i];
    }
}

char** lee_productos(ifstream &input){
    char**codigo_nombre;
    codigo_nombre = new char*[2];
    codigo_nombre[0] = leer_cadena(input, 8, ',');
    codigo_nombre[1] = leer_cadena(input, 200, ',');
    return codigo_nombre;
}

void prueba_lectura_productos(char*** productos, int* stock, 
                              double* precios, const char*nombre_archivo){
    char **aux_productos;
    ofstream output(nombre_archivo, ios::out);
    if(not output.is_open()){
        cout<< "Error no se abrio el"<<nombre_archivo<<endl;
        exit(1);
    }
    
    for(int i=0; productos[i]; i++){
        aux_productos = productos[i];
        output << setw(10)<<aux_productos[0];
        output << setw(60)<<aux_productos[1];
        output << setw(10)<<precios[i];
        output << setw(10)<<stock[i]<<endl;
    }
}
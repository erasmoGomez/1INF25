/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "functions.hpp"

void* leer_enteros(ifstream&){
    
}

void* leer_registro(ifstream&input){
    int *codigo, cod;
    char *nombre, buffer[60];
    double *sueldo;
    //Codigo 123456, nombre Erasmo Montoya, sueldo 2.5
    void**registro;
    input>>cod;
    if(input.eof())return nullptr;
    input.get();
    codigo = new int;
    *codigo = cod;
    input.getline(buffer, 60, ',');
    nombre = new char[strlen(buffer)+1];
    strcpy(nombre, buffer);
    sueldo = new double;
    input>>*sueldo;
    
    registro = new void*[3];
    registro[COD] = codigo;
    registro[NOM] = nombre;
    registro[SUE] = sueldo;
    return registro;
    
}

int cmp_registro(const void*, const void*){
    
}

void crear_lista(void*lista, void*(*lee)(ifstream&), int(*cmp)(const void*, const void*)){
    ifstream input("personal.csv");
    lista = nullptr;
    void* dato;
    while(true){
        dato = lee(input);
        if(input.eof())break;
        insertar(dato, lista, cmp);
    }
}
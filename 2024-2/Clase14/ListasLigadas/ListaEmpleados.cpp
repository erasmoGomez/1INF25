/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "ListaEmpleados.hpp"

char* leer_cadena(ifstream &input, char del){
    char buffer[60], *cad;
    input.getline(buffer,60,del);
    if(input.eof()) return nullptr;
    cad =  new char[strlen(buffer)+1];
    strcpy(cad, buffer);
    return cad;
}

void* lee_empleado(ifstream &input){
    int*cod, codigo;
    char*cad;
    double *suel, sueldo;
    void **empleado;
    // 378708,SAENZ ARANDA WILMER,23455.6
    input>>codigo;
    if(input.eof()) return nullptr;
    input.get();
    cad = leer_cadena(input, ',');
    input>>sueldo;
    cod = new int;
    suel = new double;
    *cod = codigo;
    *suel = sueldo;
    empleado = new void*[3];
    empleado[CODIGO] = cod;
    empleado[NOMBRE] = cad;
    empleado[SUELDO] = suel;
    return empleado;
    
}

int compara_empleado_nombre(const void*e1,const void*e2){
    void**reg1 = (void**)e1, **reg2 = (void**)e2;
    char*nombre1 = (char*)reg1[NOMBRE], *nombre2 = (char*)reg2[NOMBRE];
    return strcmp(nombre1, nombre2);
}

int compara_empleado_codigo(const void*e1,const void*e2){
    void**reg1 = (void**)e1, **reg2 = (void**)e2;
    int*codigo1 = (int*)reg1[CODIGO], *codigo2 = (int*)reg2[CODIGO];
    return *codigo1 - *codigo2;
}

void imprime_empleado(void*empleado){
    void**registro = (void**)empleado;
    int*codigo = (int*)registro[CODIGO];
    char*nombre = (char*)registro[NOMBRE];
    double*sueldo = (double*)registro[SUELDO];
    cout.precision(2);
    cout<<fixed;
    cout<<setw(10)<<*codigo<< "   " << left<<setw(50)<<nombre<<right<<setw(10)<<*sueldo<<endl;
}
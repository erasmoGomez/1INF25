/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "FuncionesEnteros.hpp"

void *leenum(ifstream &arch){
    void **dato;
    int numero, *num;
    arch >> numero;
    if(arch.eof()) return nullptr;
    dato = new void*[1];
    num = new int;
    *num = numero;
    dato[0] = num;
    return dato;
    
//    void *dato;
//    int numero, *num;
//    arch >> numero;
//    if(arch.eof()) return nullptr;
//    num = new int;
//    *num = numero;
//    dato = num;
//    return dato;
}

void imprimenum(ofstream &arch, void *dato){
    void**datonum = (void**)dato;
    int*num = (int*)datonum[0];
    arch << *num<<endl;
}

int cmpnum(void *dato1, void *dato2){
    void**aux1 = (void**)dato1;
    void**aux2 = (void**)dato2;
    int *num1 = (int*)aux1[DATO];
    int *num2 = (int*)aux2[DATO];
    return *num1 - *num2;
}
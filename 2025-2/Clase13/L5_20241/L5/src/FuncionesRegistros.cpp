/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "FuncionesRegistros.hpp"

char* leecadena(ifstream &arch, int max, char del) {
    char *cad, buffer[max];
    arch.getline(buffer, max, del);
    if (arch.eof())return nullptr;
    cad = new char[strlen(buffer) + 1];
    strcpy(cad, buffer);
    return cad;
}

void *leeregistro(ifstream &arch) {
    //2,14268463,BHD6079
    void **reg;
    int pedido, *ped, dni, *_dni;
    char *codigo;
    arch>>pedido;
    if (arch.eof())return nullptr;
    arch.get();
    arch>>dni;
    arch.get();
    codigo = leecadena(arch, 10, '\n');
    reg = new void*[3] {};
    ped = new int;
    _dni = new int;
    *ped = pedido;
    *_dni = dni;
    reg[PEDIDO] = ped;
    reg[DNI] = _dni;
    reg[CODIGO] = codigo;
    return reg;
}

int cmpregistro(void *reg1, void *reg2){
    void**registro1 = (void**)reg1;
    void**registro2 = (void**)reg2;
    int* id_pedido1 = (int*) registro1[PEDIDO];
    int* id_pedido2 = (int*) registro2[PEDIDO];
    return *id_pedido1-*id_pedido2;
}

void imprimeregistro(ofstream &arch, void *dato){
    void**registro = (void**)dato;
    int*pedido = (int*)registro[PEDIDO];
    int*dni = (int*)registro[DNI];
    char*codigo = (char*)registro[CODIGO];
    arch << setw(5)<<*pedido<<setw(10)<<*dni<<setw(10)<<codigo<<endl;
}
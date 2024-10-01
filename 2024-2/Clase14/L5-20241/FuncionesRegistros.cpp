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
    reg = new void*[3] {
    };
    ped = new int;
    _dni = new int;
    *ped = pedido;
    *_dni = dni;
    reg[PEDIDO] = ped;
    reg[DNI] = _dni;
    reg[CODIGO] = codigo;
    return reg;
}

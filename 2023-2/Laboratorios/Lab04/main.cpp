/* 
 * File:   main.cpp
 * Author: alulab14
 *
 * Created on 22 de septiembre de 2023, 08:12 AM
 */

#include "PunterosGenericos.h"
#include "MuestraPunteros.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    void *productos, *clientes;
    cargaproductos(productos);
    cargaclientes(clientes);
    cargapedidos(productos, clientes);
    imprimereporte(clientes);
    return 0;
}

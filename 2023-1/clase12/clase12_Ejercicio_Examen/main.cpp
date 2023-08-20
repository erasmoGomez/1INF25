/* 
 * File:   main.cpp
 * Author: Erasmo Montoya
 *
 * Created on 10 de mayo de 2023, 3:03
 */


#include "PunterosGenericos.hpp"
int main(int argc, char** argv) {
    void *productos, *pedidos, *clientes;
    cargaproductos(productos);
    cargapedidos(pedidos);
    //procesaclientes(productos, pedidos, clientes);
    //imprimereporte(clientes);
    return 0;
}

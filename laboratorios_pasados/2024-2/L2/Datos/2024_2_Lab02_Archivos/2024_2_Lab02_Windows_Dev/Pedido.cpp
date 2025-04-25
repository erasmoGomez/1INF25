/* 
 * Archivo: Pedido.cpp
 * Autor: Andrés Melgar
 * Fecha: 31 de agosto de 2024, 10:45
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include "Pedido.hpp"

using namespace std;

bool operator>>(istream &archivo_de_pedidos, Pedido &pedido) {
    archivo_de_pedidos>>pedido.dni_cliente;
    if (archivo_de_pedidos.eof())
        return false;
    archivo_de_pedidos.get(); //sacamos el blanco
    archivo_de_pedidos.getline(pedido.codigo_plato, 7, ' ');
    archivo_de_pedidos>>pedido.cantidad_platos;
    archivo_de_pedidos.get(); //sacamos el blanco
    archivo_de_pedidos.getline(pedido.codigo_repartidor, 7);         
    return true;
}

ostream & operator<<(ostream &out, const Pedido &pedido){   
    out<<setw(10)<<pedido.dni_cliente;
    out<<setw(10)<<pedido.codigo_plato;
    out<<setw(4)<<pedido.cantidad_platos;
    out<<setw(10)<<pedido.codigo_repartidor;
    return out;
}
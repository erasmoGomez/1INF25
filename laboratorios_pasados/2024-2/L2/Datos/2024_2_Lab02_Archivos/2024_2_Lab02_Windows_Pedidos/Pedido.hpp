/* 
 * Archivo: Pedido.hpp
 * Autor: Andrés Melgar
 * Fecha: 31 de agosto de 2024, 10:41
 */

#ifndef PEDIDO_HPP
#define PEDIDO_HPP

#include <iostream>
#include <fstream>

using namespace std;

struct Pedido{
    int dni_cliente;
    char codigo_plato[7];
    int cantidad_platos;
    char codigo_repartidor[7];
};

bool operator>>(istream &archivo_de_pedidos, Pedido &pedido);

ostream & operator<<(ostream &out, const Pedido &pedido);

#endif /* PEDIDO_HPP */


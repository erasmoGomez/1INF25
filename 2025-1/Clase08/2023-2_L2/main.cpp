/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Erasmo Gomez
 * Description: 
 * Created on April 8, 2025, 6:29 PM
 */
#include "funciones.hpp"
/*
 * 
 */
int main(int argc, char** argv) {
    char***productos, ***codigos_pedidos;
    int *stock, *fechas, ***dni_cantidad_pedidos;
    double *precios;
    lectura_productos(productos, stock, precios, "Productos.csv");
    prueba_lectura_productos(productos, stock, precios, "prueba_productos.txt");
    lectura_pedidos(fechas, codigos_pedidos, dni_cantidad_pedidos, "Pedidos.csv");
    return 0;
}


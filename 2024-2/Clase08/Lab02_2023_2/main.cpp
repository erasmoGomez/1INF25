/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Erasmo G. Montoya
 *
 * Created on September 10, 2024, 6:08 PM
 */

#include "funciones.hpp"

/*
 * 
 */
int main(int argc, char** argv) {
    char ***productos, ***codigos_pedidos;
    int *stock, *fechas, ***dni_cantidad_pedidos;
    double *precios;
    lectura_productos(productos, stock, precios, "Productos.csv");
    prueba_lectura_productos(productos, stock, precios, "reporte.txt");
    
    lectura_pedidos(fechas, codigos_pedidos, dni_cantidad_pedidos, "Pedidos.csv");
    prueba_lectura_pedidos(fechas, codigos_pedidos, dni_cantidad_pedidos, "reporte2.txt");
    return 0;
}


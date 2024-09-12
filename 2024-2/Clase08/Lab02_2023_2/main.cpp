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
    char*** productos;
    int *stock;
    double *precios;
    lectura_productos(productos, stock, precios, "productos.csv");
    prueba_lectura_productos(productos, stock, precios, "reporte.txt");
    return 0;
}


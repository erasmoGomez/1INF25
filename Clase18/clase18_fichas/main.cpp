/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: erasmog
 *
 * Created on June 14, 2023, 10:45 PM
 */

#include "MovimientosTablero.hpp"

/*
 * 
 */
int main(int argc, char** argv) {
//    Fa f;
//    f.asigna("F1", 5, 10);
//    ofstream arch("salida.txt", ios::out);
//    f.imprime(arch);
//    Tablero t;
//    ifstream arch("Fichas.txt", ios::in);
//    ifstream arch2("Movimientos.txt", ios::in);
//    t.leer_fichas(arch);
//    t.leer_movimiento(arch2);
    MovimientosTablero juego;
    juego.cargar_mover_fichas("Fichas.txt", "Movimientos.txt", "Salida.txt");
    return 0;
}


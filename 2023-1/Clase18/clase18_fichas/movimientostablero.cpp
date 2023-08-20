/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "MovimientosTablero.hpp"

void MovimientosTablero::cargar_mover_fichas(const char* nombre_arch_fichas, 
                         const char* nombre_arch_movimientos, 
                         const char* nombre_arch_reporte){
    
    ifstream arch_fichas(nombre_arch_fichas, ios::in);
    ifstream arch_movientos(nombre_arch_movimientos, ios::in);
    ofstream arch_reporte(nombre_arch_reporte, ios::out);
    
    tablero.leer_fichas(arch_fichas);
    arch_reporte<<"Posiciones iniciales de las fichas"<<endl;
    tablero.imprime_datos(arch_reporte);
    arch_reporte<<endl<<endl;
    tablero.leer_movimiento(arch_movientos);
    arch_reporte<<"Posiciones finales de las fichas"<<endl;
    tablero.imprime_datos(arch_reporte);
    
}
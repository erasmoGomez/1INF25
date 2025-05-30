/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Erasmo Gomez
 * Description: 
 * Created on May 28, 2025, 4:00 PM
 */

#include "Biblioteca.hpp"

/*
 * 
 */
int main(int argc, char** argv) {
    Biblioteca biblioteca;
    biblioteca.cargar_libros();
    biblioteca.cargar_estantes();
    biblioteca.posicionar_libros();
    biblioteca.mostrar_datos();
    
    return 0;
}


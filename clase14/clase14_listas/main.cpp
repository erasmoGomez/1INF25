/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: erasmog
 *
 * Created on May 30, 2023, 7:02 AM
 */

#include "funciones.hpp"

/*
 * 
 */
int main(int argc, char** argv) {
    void * lista;
    void * lista_reg;
    ifstream arch("datos.txt", ios::in);
    ifstream arch_registros("personal.csv", ios::in);
    //Forma 1 de insercion
    crear_lista(arch, lista, leer_entero);
    imprimir_lista(lista, imprimir_entero);
    
    //Forma 2 insertar ordenado
    crear_lista(arch_registros, lista_reg, leer_registro, cmp_registro_multi_criterio);

    imprimir_lista(lista_reg, imprimir_registro);
    eliminar_lista(lista_reg, eliminar_registro);
    return 0;
}


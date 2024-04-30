/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Erasmo G. Montoya
 *
 * Created on April 25, 2024, 7:58 AM
 */

#include "functions.hpp"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    void* lista_registros;
    void* lista_enteros;
    crear_lista("personal.csv",lista_registros, leer_registro, cmp_registro_str);
    //crear_lista("enteros.csv",lista_enteros, leer_enteros, cmp_enteros);
    
//crear_lista(lista_enteros, leer_enteros, cmp_enteros);
    imprime_lista("lista_personal.txt",lista_registros, imprime_registro);
    //imprime_lista("lista_enteros.txt",lista_enteros, imprime_enteros);
    
    eliminar_lista(lista_registros, elimina_registro);
    //qsort();
    return 0;
}


/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Erasmo G. Montoya
 *
 * Created on September 25, 2023, 3:57 AM
 */

#include "lista_generica.hpp"
// #include "grafo_dirigido_generico.hpp"
#include "operaciones_void.hpp"

/*
 * 
 * 
 */
int main(int argc, char** argv) {

    void *lista;
    crear_lista("personal.csv", lista, leer_registro, cmp_registros_nombre);
    //    crear_lista("datos_enteros.csv", lista, leer_enteros, cmp_enteros);
    //    crear_lista("datos_enteros.csv", lista, leer_canciones, cmp_canciones);
    imprimir_lista("output.txt", lista, imprimir_registro);
    eliminar_lista(lista, eliminar_registro);
    cout<<argc<<endl;
    cout<<argv[0]<<endl;
    cout<<argv[1]<<endl;
    return 0;
}


/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Erasmo G. Montoya
 *
 * Created on September 30, 2024, 4:59 PM
 */

#include "ListaGenerica.hpp"
#include "ListaEmpleados.hpp"

/*
 * 
 */
int main(int argc, char** argv) {
    void* lista_empleados;
    crear_lista("personal.csv", lista_empleados, lee_empleado, compara_empleado_nombre);
    imprimir_lista(lista_empleados, imprime_empleado);
    return 0;
}


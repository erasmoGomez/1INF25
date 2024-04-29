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
    void* lista;
    crear_lista(lista, leer_registro, cmp_registro);
    return 0;
}


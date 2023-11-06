/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Erasmo G. Montoya
 *
 * Created on October 31, 2023, 7:33 AM
 */

#include "Lista.hpp"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    class Lista lista;
    lista.crear();
    lista.imprimir();
    lista.imprimir_recursivo();
    return 0;
}


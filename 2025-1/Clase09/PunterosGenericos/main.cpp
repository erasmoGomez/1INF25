/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Erasmo Gomez
 * Description: 
 * Created on April 15, 2025, 6:35 PM
 */

#include "utils.hpp"

/*
 * 
 */

void imprimir(void*p, char c) {
    if (c == 'i')
        cout << ((char*) p)[0] << endl;
    else
        cout << *(double*) p << endl;
}

int main(int argc, char** argv) {
    int a = 65;
    double b = 234.678;
    cout << "Desde el main: " << &a << endl;
    imprimir(&a, 'i');
    imprimir(&b, 'd');
    return 0;
}


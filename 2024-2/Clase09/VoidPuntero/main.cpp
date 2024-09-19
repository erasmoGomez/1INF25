/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Erasmo G. Montoya
 *
 * Created on September 16, 2024, 5:57 PM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

/*
 * 
 */

void imprimir(void*p, char c){
    if(c == 'i')
        cout<<*(int*)p<<endl;
    else
        cout<<*(double*)p<<endl;
}

int main(int argc, char** argv) {
    int a = 5;
    double b = 234.678;
    imprimir(&a, 'i');
    imprimir(&b, 'd');
    return 0;
}


/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Erasmo G. Montoya
 *
 * Created on March 31, 2024, 3:43 PM
 */

#include <iostream>
#include "Tweet.hpp"
#include "functions.hpp"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int *p;
    int a[5]{10,5,8,-5,4};
    cout<<p<<endl; //Direccion de memoria de un entero
    p = a;
    cout<<p<<endl; //Direccion de memoria del primer elemento del arreglo a
    cout<<*p<<endl; // VALOR del elemento alojado en la direccion de memoria del primer elemento del arreglo
    cout<<*(p+2)<<endl; //Valor del 3er elemento, al sumarle 2 a la direccion de memoria se aumentas 2*4 espacios donde 4 es el size(int)
    p = &a[3];
    cout<<*p<<endl; //Ahora p apunta a la direccion de memoria del 4er elemento del arreglo;
    cout<<*(p+1)<<endl; // Usando aritmetica de punteros podemos acceder al siguiente elemento
    p = new int;
    delete p;
    cout<<"Que es esto?: "<<*p<<endl; // Luego de liberar no sabemos q puede haber ahi.
    int *p1;
    p1 = new int[10]{};
    //while(p1)cout<<*p1<<" "<<endl; //Esto se queda en bucle x q no se como termina
    p1[0] = 5;
    p1[1] = 10;
    p1[2] = 11; 
    while(*p1)cout<<*p1++<<" "<<endl; // Esto imrprime la lista hasta q no sea un 0
    
    //Llamar a funciones con const
    Tweet t;
    f(t);
    //f1(t); //Error x q F1 recibe el T como const y G no recibe como const
    t.created_at = 240401;
    f2(t);
    
    //Ahora con punteros p1 {12,6,-4}
    int *p2;
    p2 = new int[10]{};
    p2[0] = 12;
    p2[1] = 6;
    p2[2] = -4; 
    h(p2);
    // h1(p2); //error x q es const
    h2(p2);
    // h3(p2); //error x q es const
    return 0;
}


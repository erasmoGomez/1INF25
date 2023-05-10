/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: erasmog
 *
 * Created on May 9, 2023, 2:09 AM
 */

#include <iostream>
#include <iomanip>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    void *ptr1, **ptr2;
    int entero = 23, *ptr3;
    double flotante = 1.67, *ptr4;
    char nombre[50] = "Erasmo Gomez Montoya";
    
    ptr3 = &entero;
    ptr4 = &flotante;
    
    cout<<*ptr3<<endl;
    cout<<*ptr4<<endl;
    
    ptr1 = &entero;
    ptr1 = &flotante;
    ptr1 = nombre;
    cout<<(char*)ptr1<<endl;
    
    ptr1 = new int;
    
    *(int*)ptr1 = 99;
    cout<<*(int*)ptr1<<endl;
    cout<<entero<<endl;
    return 0;
}


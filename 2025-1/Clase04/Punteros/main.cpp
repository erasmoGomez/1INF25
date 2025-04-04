/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: hecto
 *
 * Created on April 1, 2025, 5:44 PM
 */

#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int arr[5]{10,10,20,5,12};
    int x = 5;
    int *p;
    cout<<*p<<endl;
    cout<<p<<endl;
    p = &x;
    cout<<&x<<endl;
    cout<<p<<endl;
    cout<<*p<<endl;
    
    int *q;
    cout<<"*q"<<endl;
    cout<<arr<<endl;
    cout<<&arr[0]<<endl;
    q = arr;
    cout<<q<<endl;
    
    int *z;
    z = new int[4]; //Reserva de memoria new int -> new int[1]
    z[0] = 1;
    z[1] = 2;
    z[2] = 3;
    z[3] = 4;
    cout<<z[2]<<endl;        
    
    return 0;
}


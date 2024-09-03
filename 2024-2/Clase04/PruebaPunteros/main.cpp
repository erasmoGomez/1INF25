/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Erasmo G. Montoya
 *
 * Created on August 27, 2024, 6:49 PM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int *p;
    int x = 27;
    int arr[5];
    cout<<p<<endl;
    cout<<&x<<endl;
    p = &x;
    cout<<p<<endl;
    cout<<&x<<endl;
    cout<<"Arreglo: "<<&arr<<endl;
    p = arr;
    cout<<p<<endl;
    return 0;
}


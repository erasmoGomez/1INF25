/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Erasmo G. Montoya
 *
 * Created on September 19, 2023, 9:25 AM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

/*
 * 
 */
int suma(int a, int b){
    return a+b;
}

int resta(int a, int b){
    return a-b;
}

int multiplica(int a, int b){
    return a*b;
}

int division(int a, int b){
    return a/b;
}

int adicional(int a, int b){
    return a%b;
}

int operacion_generica(int a, int b, int (*puntero_funcion)(int, int)){
    int t;
    t = puntero_funcion(a,b);
    return t;
}

int compara_enteros(const void* a, const void*b){
    int *ai = (int*)a;
    int *bi = (int*)b;
    return *ai - *bi;
}

int main(int argc, char** argv) {
//    int a = 10, b = 5, c;
//    c = operacion_generica(a, b, suma);
//    cout<< c<< endl;
//    
//    int (*pt[5]) (int, int);
//    pt[0] = suma;
//    pt[1] = resta;
//    pt[2] = multiplica;
//    pt[3] = division;
//    pt[4] = adicional;
//    
//    c = pt[3](a,b); // c = division(a,b);
//    cout<<c<<endl;
    
    int arr[10] = {5,8,2,4,6,1} ;// 6 elementos
    int n=6;
    cout<<"Unsorted"<<endl;
    for (int i=0; i<n;i++)
        cout<<arr[i]<<endl;
    qsort(arr, n, sizeof(int), compara_enteros );
    cout<<"Sorted"<<endl;
    for (int i=0; i<n;i++)
        cout<<arr[i]<<endl;
    return 0;
}


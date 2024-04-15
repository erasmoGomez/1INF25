/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Erasmo G. Montoya
 *
 * Created on April 10, 2024, 8:35 AM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

/*
 * 
 */

int main(int argc, char** argv) {
    void * generico, * generico1;
    int a = 64;
    char b[20] = "hola q tal";
    generico = &a;
    cout<< generico<<endl;
    cout<< &a <<endl;
    
    cout<< *(int *)generico <<endl; // C orrecto
    cout<< a <<endl;
    
    cout<< (char*)generico <<endl;
    
    generico1 = b;
    
    cout<< (char*) generico1 <<endl; //Correcto
    cout<< *(int*) generico1 <<endl;
    cout<< ((int*) generico1)[3] <<endl;

    return 0;
}


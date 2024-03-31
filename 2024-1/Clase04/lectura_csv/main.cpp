/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Erasmo G. Montoya
 *
 * Created on March 25, 2024, 6:19 PM
 */
#include "Sobrecargas.hpp"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    ifstream input("personas.csv",ios::in);
    Persona p;
    struct Persona personas[20];
    int n = 0;
    
//    while(true){
//        input>>personas[n];
//        if (input.eof())break;
//        n++;
//    }
//    
//    for(int i=0; i<n; i++)
//        cout<<personas[i];
    
    while(input>>personas[n++]);
    
    n = 0;
    while(input>>p){
        personas[n] = p;
        n++;
    }
    
    while(true){
        if(input>>p){
            personas[n] = p;
            n++;
        } 
    }
    
    for(int i=0; i<n; i++) cout<<personas[i];
    return 0;
}


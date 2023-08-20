/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: erasmog
 *
 * Created on April 25, 2023, 6:31 AM
 */

#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    char nombre[100];
    char *nomb;
    char n[9];
    nomb = new char[100];
    int num;
    
//    cin.getline(nombre, 100);
//    cin.getline(nomb,100);
//    cout<<nombre<<endl;
//    cout<<nomb<<endl;
    
//    strcpy(nomb, "Erasmo Gomez Montoya");
//    cout<<nomb<<endl;
//    cin.getline(n,9);
//    if(cin.fail()) cin.clear();
//    cin.getline(nomb,100);
//    cout<<n<<endl;
//    cout<<nomb<<endl;
    
    cin.getline(nombre,100);
    int n_cadena ;
    n_cadena = strlen(nombre);
    char *nombre_chevere;
    nombre_chevere = new char(n_cadena+1);
    cout<<nombre_chevere<<endl;
    strcpy(nombre_chevere, nombre);
    cout<<nombre_chevere<<endl;
    
    cout<<"Tamano: "<<strlen(nombre_chevere)<<endl;
    return 0;
}


/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Erasmo G. Montoya
 *
 * Created on March 31, 2024, 12:02 AM
 */

#include "Sobrecargas.hpp"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    //Prueba sobrecarga escritura terminal
    Persona p{5555555,"Erasmo Gomez", 167.5,105.6};
    cout<<p;
    
    //Prueba sobrecarga lectura archivo
    Persona p2;
    ifstream input("test_input.txt", ios::in);
    input>>p2;
    //Prueba sobrecarga escritura archivo
    ofstream output("reporte.txt", ios::out);
    output<<p2;
    return 0;
}


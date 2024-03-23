/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Erasmo G. Montoya
 *
 * Created on March 22, 2024, 11:54 AM
 */

#include "Sobrecargas.hpp"
//#include "Functions.hpp"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    ifstream input("personas.txt", ios::in);
    ofstream output("reporte.txt", ios::out);
    struct Persona people[20];
    struct Persona p;
    input>>p;
    people[0] = p;
    return 0;
}


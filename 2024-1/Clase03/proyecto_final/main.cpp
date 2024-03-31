/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Erasmo G. Montoya
 *
 * Created on March 25, 2024, 5:44 PM
 */

#include "Sobrecargas.hpp"
#include "Functions.hpp"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    ifstream input("personas.txt", ios::in);
//    input>>p2;
//    cout<<p2;
    ofstream output("reporte.txt", ios::out);
    struct Persona people[20];
    read_people(input, people);
    display_people(output, people);
    return 0;
}


/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Erasmo G. Montoya
 *
 * Created on March 20, 2024, 7:59 AM
 */

#include "Sobrecargas.hpp"
#include "Functions.hpp"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
//    Persona p, p2;
//    p.dni = 12345321;
//    strcpy(p.name,"Erasmo_Gomez");
//    p.weight = 100.5;
//    p.height = 1.67;
//    add_headers();
//    cout<<p;
    
//    ifstream input("personas.txt", ios::in);
////    input>>p2;
//    cout<<p2;
//    ofstream output("reporte.txt", ios::out);
//    struct Persona people[20];
//    read_people(input, people);
//    display_people(output, people);
    ifstream input("personas.txt", ios::in);
    ofstream output("reporte.txt", ios::out);
    struct Persona people[20];
    struct Persona p;
    input>>p;
    people[0] = p;
    return 0;
}


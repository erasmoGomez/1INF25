/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Erasmo G. Montoya
 *
 * Created on August 23, 2023, 6:52 AM
 */

#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
#include "Estructuras.hpp"
#include "Persona.hpp"
#include "Sobrecargas.hpp"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    ifstream input_cursos("cursos.csv", ios::in);
    ifstream input_alumnos("alumnos.csv", ios::in);
    StCurso cursos[10];
    StAlumno alumnos[200];
    int i = 0;
    bool b;
    while (true){
        b = input_alumnos >> alumnos[i];
        if (!b) break;
        cout<<alumnos[i].codigo<<endl;
        cout<<alumnos[i].semestre<<endl;
        cout<<alumnos[i].nombre<<endl;
        cout<<alumnos[i].escala<<endl;
        cout<<alumnos[i].modalidad<<endl;
        i++;
    }
    return 0;
}

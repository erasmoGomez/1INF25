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
    ifstream input_registros("matricula.csv", ios::in);
    ofstream output("output.txt", ios::out);
    StCurso cursos[50];
    StAlumno alumnos[200];
    StRegistroDeMatricula registros[200];
    int i = 0, n_cursos =0, n_alumnos =0, n_registros =0;
    bool b;
    //Lectura
    while (true){
        b = input_cursos >> cursos[i];
        if (!b) break;
//        cout<<cursos[i].codigoDelCurso<<endl;
//        cout<<cursos[i].nombreDelCurso<<endl;
//        cout<<cursos[i].creditos<<endl;
//        cout<<cursos[i].codigoDelProfesor<<endl;
//        cout<<cursos[i].nombreDelProfesor<<endl;
        i++;
    }
    n_cursos = i;
    strcpy(cursos[n_cursos].codigoDelCurso,"XXXXXX");
    
    i=0;
    
    while (true){
        b = input_alumnos >> alumnos[i];
        if (!b) break;
//        cout<<alumnos[i].codigo<<endl;
//        cout<<alumnos[i].semestre<<endl;
//        cout<<alumnos[i].nombre<<endl;
//        cout<<alumnos[i].escala<<endl;
//        cout<<alumnos[i].modalidad<<endl;
        i++;
    }
    n_alumnos = i;
    i=0;
    while (true){
        b = input_registros >> registros[i];
        if (!b) break;
//        cout<<registros[i].codigoDelCurso<<endl;
//        cout<<registros[i].codigodelAlumno<<endl;
//        cout<<registros[i].semestreDelAlumno<<endl;
        i++;
    }
    n_registros = i;
    //Asignacion
    StCurso nuevo_curso;
    strcpy(nuevo_curso.codigoDelCurso,"INF2081");
    strcpy(nuevo_curso.nombreDelCurso,"Lenguajes de Programacion 1");
    nuevo_curso.codigoDelProfesor = 20082060;
    strcpy(nuevo_curso.nombreDelProfesor,"Erasmo Montoya");
    nuevo_curso.creditos = 5;
            
    cursos+=nuevo_curso;
    
    //output<<cursos[n_cursos]; //El ultimo curso
    
    StAlumno nuevo_alumno;
    nuevo_alumno.codigo = 20082060;
    nuevo_alumno.semestre = 20231;
    strcpy(nuevo_alumno.nombre,"Kelvin Zacalla");
    strcpy(nuevo_alumno.modalidad,"Semi-Presencial");
    nuevo_alumno.escala = 5;
    nuevo_alumno.porcentaje = 30;
            
    alumnos+=nuevo_alumno;
    //output<<alumnos[n_alumnos]; //El ultimo alumno
    for (int i = 0; i<n_registros-1;i++){
        cursos*=registros[i];
    }
    for (int i = 0; i<n_registros-1;i++){
        alumnos*=registros[i];
    }
    for(int i =0; i<n_cursos;i++){
        output<<cursos[i]; 
    }
    for(int i =0; i<n_cursos;i++){
        output<<alumnos[i]; 
    }
}

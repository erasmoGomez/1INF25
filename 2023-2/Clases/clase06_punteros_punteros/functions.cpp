/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include "functions.hpp"
using namespace std;

char * leer_cadena_over(ifstream &input){
    char *cadena;
    cadena = new char[7];
    input.get(cadena, 7);
    return cadena;
}

char ** leer_cursos(ifstream &input){
    char *buffer_cursos[30]{}, *curso, **cursos;
    int n_cursos = 0;
    while(true){
        curso = leer_cadena_over(input); //Devuelve char*
        buffer_cursos[n_cursos] = curso;
        n_cursos++;
        //Si es diferente de la coma, es decir fin de linea o eof me voy
        if(input.get()!=',') break; 
    }
    n_cursos++;
    //Reservo memoria para los cursos del alumno
    cursos = new char*[n_cursos];
    //Asigno los valores al puntero cursos usando el buffer_cursos
    //donde almacene previamente
    for(int i=0; i<n_cursos;i++)
        cursos[i] = buffer_cursos[i];
    return cursos;
}

char * leer_cadena(ifstream &input){
    char buffer[100], *nombre;
    input.getline(buffer,100,','); // Leo buffer
    nombre = new char[strlen(buffer) + 1]; // Reservo memoria
    strcpy(nombre, buffer); // Asigno valor
    return nombre;
}

void cargar_alumnos(int *& codigo, char **& nombre, char ***& cursos, 
                    const char* nombre_archivo){
    int cod, aux_codigos[30]{}, n_datos = 0;
    char *aux_nombres[30]{};
    char **aux_cursos[30]{};
    ifstream input(nombre_archivo, ios::in);
    if(not input.is_open()){
        cout<<"ERROR: "<<nombre_archivo<<endl;
        exit(1);
    }
    while(true){
        //Lectura por linea
        input>>cod;
        if(input.eof())break;
        input.get();
        aux_codigos[n_datos] = cod;
        aux_nombres[n_datos] = leer_cadena(input);
        aux_cursos[n_datos] = leer_cursos(input);
        n_datos++;
    }
    n_datos++; //para usar el valor en la reserva de espacios
    //reserva de memoria
    codigo = new int[n_datos];
    nombre = new char *[n_datos];
    cursos = new char **[n_datos];
    //asignacion de valores
    for(int i=0;i<n_datos;i++){
        codigo[i] = aux_codigos[i];
        nombre[i] = aux_nombres[i];
        cursos[i] = aux_cursos[i];
    }
}

void reporte_cursos(char **cursos_por_alumno, ofstream &output){
    for(int i=0; cursos_por_alumno[i]; i++)
        output<<right<<setw(15)<<cursos_por_alumno[i]<<endl;
}

void reporte_alumnos(int * codigo, char ** nombre, char *** cursos, 
                    const char* nombre_archivo){
    ofstream output(nombre_archivo, ios::out);
    for(int i=0; codigo[i]; i++){
        //output<<codigo[i]<<endl;
        output<<left<<setw(10)<<codigo[i]<<nombre[i]<<endl;
        reporte_cursos(cursos[i], output);
    }

}
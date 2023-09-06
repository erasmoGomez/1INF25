/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include "funciones.hpp"
using namespace std;
char * leer_cadena(ifstream &input){
    char buffer[100], *cadena;
    input.getline(buffer,100, ',');
    cadena  = new char[strlen(buffer)+1]; //El espacio para el \0
    strcpy(cadena, buffer);
    return cadena;   
}

void lectura_alumnos(const char* nombre_archivo,
                     int *& codigos, char **& nombres,
                     char *& modalidades,int *& porcentajes,
                     int *& escalas){
    int codigo, n_datos = 0,porcentaje,escala;
    int buffer_codigos[100], buffer_porcentaje[100], buffer_escala[100];
    char * buffer_nombres[100], buffer_modalidad[100], modalidad;
    ifstream input(nombre_archivo, ios::in);
    while(true){
        input>>codigo;
        if(input.eof()) break;
        input.get();
        buffer_codigos[n_datos] = codigo;
        buffer_nombres[n_datos] = leer_cadena(input);
        input>>modalidad;
        input.get();
        buffer_modalidad[n_datos] = modalidad;
        input>>porcentaje;
        input.get();
        buffer_porcentaje[n_datos] = porcentaje;
        input>>escala;
        input.get();
        buffer_escala[n_datos] = escala;
        n_datos++;
    }
    
    buffer_codigos[n_datos] = 0;
    buffer_nombres[n_datos] = nullptr;
    buffer_modalidad[n_datos] = 0;
    buffer_porcentaje[n_datos] = 0;
    buffer_escala[n_datos] = 0;
    n_datos++;
    
    // Reservar de Memoria Exacta
    codigos = new int[n_datos];
    nombres = new char*[n_datos];
    modalidades = new char[n_datos];
    porcentajes = new int[n_datos];
    escalas = new int[n_datos];
    
    for(int i=0; i<n_datos; i++){
        codigos[i] = buffer_codigos[i];
        nombres[i] = buffer_nombres[i];
        modalidades[i] = buffer_modalidad[i];
        porcentajes[i] = buffer_porcentaje[i];
        escalas[i] = buffer_escala[i];
    }
}

void prueba_lectura_alumnos(const char* nombre_archivo,
                            int *codigos, char **nombres,
                            char *modalidades,int *porcentajes,
                            int *escalas){
    ofstream output(nombre_archivo, ios::out);
    if(not output.is_open()){
        cout<<"Error: No se pudo abrir :(";
        exit(1);
    }
    output.precision(2);output<<fixed;
    
    for(int i=0; codigos[i]; i++){
        output<<left<<setw(10)<<codigos[i]<<setw(60)<<nombres[i];
        output<<setw(5)<<modalidades[i];
        output<<setw(10)<<porcentajes[i];
        output<<setw(10)<<escalas[i]<<endl;
    }
}
int obtener_pos(char *nombre_curso, char **buffer_nombres_cursos, int n_datos){
    for(int i=0; i<n_datos; i++)
        if (!strcmp(buffer_nombres_cursos[i],nombre_curso)){
            return i;
        }
    return -1;
}

int encontrar_indice_alumno(int codigo_alumno, int *codigos){
    for(int i=0; codigos[i]; i++){
        if(codigos[i] == codigo_alumno)
            return i;
    }
    return -1;
}

void agregar_alumnos(int *codigos, int *escalas, int **buffer_alumnos_cursos,
                     int *n_cursos_alumnos, int pos, int n_datos, int codigo_alumno){
    int *cada_alumno, pos_alumno;
    if (pos == -1){
        cada_alumno = buffer_alumnos_cursos[n_datos - 1]; 
        cada_alumno[2*n_cursos_alumnos[n_datos -1]] = codigo_alumno;
        pos_alumno = encontrar_indice_alumno(codigo_alumno, codigos);
        cada_alumno[2*n_cursos_alumnos[n_datos -1]+1] = escalas[pos_alumno];
        n_cursos_alumnos[n_datos -1]++;
    }
    else {
        cada_alumno = buffer_alumnos_cursos[pos]; 
        cada_alumno[2*n_cursos_alumnos[pos]] = codigo_alumno;
        pos_alumno = encontrar_indice_alumno(codigo_alumno, codigos);
        cada_alumno[2*n_cursos_alumnos[pos]+1] = escalas[pos_alumno];
        n_cursos_alumnos[pos]++;
    }
    
}

void pasar_buffer_cursos(char **&nombres_cursos, double *&creditos_cursos,
                        int **&alumnos_cursos,
                        char **buffer_nombres_cursos, double *buffer_creditos_cursos,
                        int **buffer_alumnos_cursos, int n_datos, int*n_cursos_alumnos){
    int *curso_auxiliar_alumno;
    int *curso_auxiliar;
    int i,j;
    //Reservar Memoria Exacta
    nombres_cursos = new char*[n_datos+1];
    creditos_cursos = new double[n_datos+1];
    alumnos_cursos = new int*[n_datos+1];
    
    for(i=0; i<n_datos; i++){
        nombres_cursos[i] = buffer_nombres_cursos[i];
        creditos_cursos[i] = buffer_creditos_cursos[i];
        curso_auxiliar_alumno = new int[2*n_cursos_alumnos[i]+1];
        curso_auxiliar = buffer_alumnos_cursos[i]; //Aterrizaje
        for(j=0; j<n_cursos_alumnos[i];j++){
            curso_auxiliar_alumno[2*j] = curso_auxiliar[2*j];
            curso_auxiliar_alumno[2*j+1] = curso_auxiliar[2*j+1];
        }
        alumnos_cursos[i] = curso_auxiliar_alumno;
        curso_auxiliar_alumno[2*j] = 0;
    }
    nombres_cursos[i] = nullptr;
    alumnos_cursos[i] = nullptr;
    creditos_cursos[i] = -1.0;
}

void lectura_cursos(const char* nombre_archivo, int* codigos,int* escalas,
                    char**& nombres_cursos, double *& creditos_cursos, 
                    int **& alumnos_cursos){
    ifstream input(nombre_archivo, ios::in);
    int n_datos = 0, codigo_alumno, pos;
    double credito_curso, buffer_creditos_cursos[100];
    char * nombre_curso, *buffer_nombres_cursos[100];
    int *buffer_alumnos_cursos[100];
    int n_cursos_alumnos[100];
    for(int i=0;i<100;i++)
        n_cursos_alumnos[i]=0; //Inicializamos contadores de cursos
    while(true){
        input>>codigo_alumno; //No se almacena
        if(input.eof())break;
        input.get();
        nombre_curso = leer_cadena(input); // auxiliar para el nombre
        input>>credito_curso;
        
        pos = obtener_pos(nombre_curso, buffer_nombres_cursos, n_datos);
        if(pos == -1){
            //Insertarlo
            buffer_nombres_cursos[n_datos] = nombre_curso;
            buffer_creditos_cursos[n_datos] = credito_curso;
            buffer_alumnos_cursos[n_datos] = new int[200];
            cout<<buffer_nombres_cursos[n_datos];
            cout<<"        ";
            cout<<buffer_creditos_cursos[n_datos]<<endl;
            n_datos++;
        }
        agregar_alumnos(codigos,escalas,buffer_alumnos_cursos,
                        n_cursos_alumnos,pos,n_datos,codigo_alumno);
    }
    pasar_buffer_cursos(nombres_cursos,creditos_cursos,alumnos_cursos,
                        buffer_nombres_cursos,buffer_creditos_cursos,
                        buffer_alumnos_cursos,n_datos,n_cursos_alumnos);
}

void prueba_lectura_cursos(const char* nombre_archivo, char ** nombres_cursos,
                           double *creditos_cursos, int**alumnos_cursos){
    ofstream output(nombre_archivo, ios::out);
    int *cada_curso;
    for (int i = 0; nombres_cursos[i]; i++) {
        output<<left<<setw(75)<<nombres_cursos[i]<<right<<setw(15);
        output<<fixed<<setprecision(2)<<creditos_cursos[i]<<endl;
        cada_curso = alumnos_cursos[i];
        
        for(int j =0; cada_curso[j]; j+=2){
            output<<left<<setw(15)<<cada_curso[j]<<setw(15)<<cada_curso[j+1]<<endl;
        }
    }

}
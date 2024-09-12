/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Funciones.hpp"

int buscar_alumno(int codigo_alumno, int* codigos){
    for (int i=0; codigos[i]; i++){
        if(codigo_alumno == codigos[i]) return i;
    }
    return -1;
}

char* leer_cadena(ifstream &input, char delimitador) {
    char* cadena, buffer[100];
    input.getline(buffer, 100, delimitador);
    //if(input.eof()) return nullptr;
    cadena = new char[strlen(buffer) + 1];
    strcpy(cadena, buffer);
    return cadena;
}

void cargar_alumnos(int*&codigos, char**&nombres, const char*nombre_archivo) {
    int capacidad = 0, n_alumnos = 0;
    int codigo = 0;
    char *nombre = nullptr;
    ifstream input(nombre_archivo, ios::in);
    if (not input.is_open()) {
        cout<<"El archivo " << nombre_archivo << "no se abrio"<<endl;
        exit(1);
    }
    codigos = nullptr;
    nombres = nullptr;
    while(true){
        input>>codigo;
        if(input.eof())break;
        input.get();
        nombre = leer_cadena(input, '\n');
        if(capacidad == n_alumnos)
            reservar_memoria_incrementos(codigos, nombres,n_alumnos, capacidad);
        codigos[n_alumnos - 1] = codigo;
        nombres[n_alumnos - 1] = nombre;
        n_alumnos++;
    }
}

void reservar_memoria_incrementos(int*&codigos, char**&nombres, 
                                  int &n_alumnos, int &capacidad){
    int *aux_codigos;
    char **aux_nombres;
    capacidad += INCREMENTO;
    if(codigos == nullptr){
        codigos = new int[capacidad]{};
        nombres = new char*[capacidad]{};
        n_alumnos = 1;
    }
    else{
        aux_codigos = new int [capacidad]{};
        aux_nombres = new char*[capacidad]{};
        for(int i=0; i< n_alumnos; i++){
            aux_codigos[i] = codigos[i];
            aux_nombres[i] = nombres[i];
        }
        delete codigos;
        delete nombres;
        codigos = aux_codigos;
        nombres = aux_nombres;
    }
}

void reservar_memoria_incrementos(char**&cursos, int&cantidad, int&capacidad){
    char** aux_cursos;
    capacidad += INCREMENTO;
    if(cursos == nullptr){
        cursos = new char*[capacidad]{};
        cantidad = 1;
    }
    else{
        aux_cursos = new char*[capacidad]{};
        for(int i=0; i<cantidad; i++)
            aux_cursos[i] = cursos[i];
        delete cursos;
        cursos = aux_cursos;
    }
}

void imprimir_alumnos(int* codigos, char** nombres, char*** cursos, const char* nombre_archivo){
    ofstream output(nombre_archivo, ios::out);
    for(int i=0; codigos[i]; i++){
        output<<left<<setw(10)<<codigos[i];
        output<<left<<setw(20)<<nombres[i];
        if(cursos[i])
            reporte_cursos(output,cursos[i]);
        else
            output<<"No se encontraron cursos"<<endl;
    }
}

void cargar_cursos(int* codigos,char*** &cursos,const char* nombre_archivo){
    ifstream input(nombre_archivo, ios::in);
    if (not input.is_open()) {
        cout<<"El archivo " << nombre_archivo << "no se abrio"<<endl;
        exit(1);
    }
    int cantidad_datos = 0, codigo, indice;
    int cantidades[50]{}, capacidades[50]{};
    while(codigos[cantidad_datos])cantidad_datos++;
    cursos = new char**[cantidad_datos+1]{};
    while(true){
        input>>codigo;
        if(input.eof())break;
        input.get();
        indice = buscar_alumno(codigo, codigos);
        if(indice!=-1){
            colocar_curso(input, cursos[indice], 
                          cantidades[indice], capacidades[indice]);
        }
        else
            while(input.get()!='\n');
    }
    
}

void colocar_curso(ifstream &input, char**&cursos, int &cantidad, int &capacidad){
    char* curso;
    curso = leer_cadena(input, '\n');
    if(cantidad == capacidad) 
        reservar_memoria_incrementos(cursos, cantidad, capacidad);
    cursos[cantidad -1] = curso;
    cantidad++;
}

void reporte_cursos(ofstream &output,char**cursos){
    for(int i=0; cursos[i]; i++)
        output<<right<<setw(15)<<cursos[i];
    output<<endl;
}
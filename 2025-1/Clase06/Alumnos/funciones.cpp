/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   funciones.cpp
 * Author: erasmo
 * 
 * Created on April 2, 2025, 4:35 PM
 */

#include "funciones.hpp"

char* leer_cadena(ifstream& input, char del) {
    char *nombre, buffer[MAX_CARACTER];
    input.getline(buffer, MAX_CARACTER, del);
    nombre = new char[strlen(buffer) + 1];
    strcpy(nombre, buffer);
    return nombre;
}

void pasar_datos(int*& codigos, char**&nombres, 
                 int* buffer_codigos, char** buffer_nombres, int n_datos){
    codigos = new int[n_datos] {};
    nombres = new char*[n_datos] {};

    for (int i = 0; i < n_datos; i++) {
        codigos[i] = buffer_codigos[i];
        nombres[i] = buffer_nombres[i];
    }
}

void leer_datos(ifstream& input, int* buffer_codigos, char**buffer_nombres, int& n_datos){
    int codigo;
    while (true) {
        input>>codigo;
        if (input.eof())break;
        input.get();
        buffer_codigos[n_datos] = codigo;
        buffer_nombres[n_datos] = leer_cadena(input, '\n');
        n_datos++;
    }
}

void cargar_alumnos(int*& codigos, char**&nombres, const char* nombre_archivo) {
    ifstream input;
    AperturaDeUnArchivoDeTextosParaLeer(input, nombre_archivo);
    int buffer_codigos[MAX_ALUMNOS]{}, n_datos = 0;
    char* buffer_nombres[MAX_ALUMNOS]{};
    leer_datos(input, buffer_codigos, buffer_nombres, n_datos);
    pasar_datos(codigos, nombres, buffer_codigos, buffer_nombres, ++n_datos);
}

int buscar(int *codigos, int codigo) {
    for (int i = 0; codigos[i]; i++)
        if (codigos[i] == codigo)return i;
    return -1;
}

void imprimir_alumnos(int* codigos, char**nombres, const char*nombre_archivo) {
    ofstream output;
    AperturaDeUnArchivoDeTextosParaEscribir(output, nombre_archivo);
    output << "CODIGOS" << setw(20) << "NOMBRES" << endl;
    for (int i = 0; codigos[i]; i++) {
        output << codigos[i] << setw(100) << nombres[i] << endl;
    }
}

void reporte_cursos(ofstream &output, char**cursos_alumnos) {
    for (int i = 0; cursos_alumnos[i]; i++)
        output << right << setw(15) << cursos_alumnos[i];
    output << endl;
}

void imprimir_alumnos(int* codigos, char**nombres, char***cursos, const char*nombre_archivo) {
    ofstream output;
    AperturaDeUnArchivoDeTextosParaEscribir(output, nombre_archivo);
    output << "CODIGOS" << setw(20) << "NOMBRES" << endl;
    for (int i = 0; codigos[i]; i++) {
        output << codigos[i] << setw(40) << nombres[i] << endl;
        if (cursos[i])
            reporte_cursos(output, cursos[i]);
        else
            output << "No se encontraron cursos" << endl;
    }
}

void agregar_curso(ifstream &input, char**cursos_alumno, int &n) {
    char *codigo = leer_cadena(input, '\n');
    cursos_alumno[n] = codigo;
    n++;
}

void recortar(char** &cursos_alumnos, int n) {
    char** cursos_alumnos_temporal;
    if (n != 0) {
        cursos_alumnos_temporal = new char*[n+1] {}; //Reserva de memoria exacta
        //Ahora pasar la informacion  previa al nuevo arreglo
        for (int i = 0; i < n; i++)
            cursos_alumnos_temporal[i] = cursos_alumnos[i];
        delete cursos_alumnos;
        cursos_alumnos = cursos_alumnos_temporal; //Apunto a la nueva direccion de memoria que contiene los datos
    } else {
        delete cursos_alumnos;
        cursos_alumnos = nullptr;
    }
}

void leer_cursos(ifstream& input, int* codigos, char***cursos, int* n_cursos_alumno){
    int codigo, pos;
    while (true) {
        input>>codigo;
        if (input.eof()) break;
        input.get();
        pos = buscar(codigos, codigo);
        if (pos != -1)
            agregar_curso(input, cursos[pos], n_cursos_alumno[pos]);
    }
}

void recortar_cursos(int n_alumnos, char***&cursos, int* n_cursos_alumno){
    for (int i = 0; i < n_alumnos; i++)
        recortar(cursos[i], n_cursos_alumno[i]);
}

void cargar_cursos(int* codigos, char***&cursos, const char*nombre_archivo) {
    ifstream input;
    AperturaDeUnArchivoDeTextosParaLeer(input, nombre_archivo);
    int n_alumnos = 0;
    while (codigos[n_alumnos])n_alumnos++; //1Nivel tamano cursos
    int n_cursos_alumno[n_alumnos]{}; // 2Nivel: Arreglo estatico que guarda la cantidad de cursos x alumno     
    //Reserva de memoria de cursos
    cursos = new char**[n_alumnos] {}; //1Nivel
    for (int i = 0; i < n_alumnos; i++) //Buffers dinámicos en 2do Nivel
        cursos[i] = new char*[MAX_CURSOS_ALUMNO];
    //Lectura
    leer_cursos(input, codigos, cursos, n_cursos_alumno);
    //recortar los espacios q no han sido utilizados
    recortar_cursos(n_alumnos, cursos, n_cursos_alumno);
}
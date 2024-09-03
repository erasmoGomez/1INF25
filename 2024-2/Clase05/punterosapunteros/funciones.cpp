/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <valarray>

#include "funciones.hpp"

void cargar_alumnos(int*&codigos, char**&nombres, const char*nombre_archivo) {
    // Definir un tamano maximo posible de datos = 50
    // Definir arreglos buffer para almacenar sus datos
    int codigos_buffer[50]{};
    char* nombres_buffer[50]{};
    int cantidad_alumnos = 0;
    int codigo;

    ifstream input(nombre_archivo, ios::in);
    if (not input.is_open()) {
        cout << "El archivo " << nombre_archivo << " no se puede abrir" << endl;
        exit(1);
    }
    //Leer y Obtengamos el numero real de datos
    while (true) {
        input>>codigo;
        if (input.eof()) break;
        input.get(); //Sacar la coma
        codigos_buffer[cantidad_alumnos] = codigo;
        nombres_buffer[cantidad_alumnos] = leer_cadena(input, '\n');
        cantidad_alumnos++;
    }
    //Reservar la memoria exacta en codigos y nombres
    codigos = new int[cantidad_alumnos + 1] {
    };
    nombres = new char*[cantidad_alumnos + 1] {
    };
    //Pasar los elementos desde los arreglos estaticos a los dinamicos
    for (int i = 0; i < cantidad_alumnos; i++) {
        codigos[i] = codigos_buffer[i];
        nombres[i] = nombres_buffer[i];
    }
}

char* leer_cadena(ifstream &input, char delimitador) {
    char* cadena, buffer[100];
    input.getline(buffer, 100, delimitador);
    //if(input.eof()) return nullptr;
    cadena = new char[strlen(buffer) + 1];
    strcpy(cadena, buffer);
    return cadena;
}

void imprimir_alumnos(int*codigos, char**nombres, const char*nombre_archivo) {
    ofstream output(nombre_archivo, ios::out);
    for (int i = 0; codigos[i]; i++) {
        output << left << setw(10) << codigos[i];
        output << left << setw(60) << nombres[i] << endl;
    }
}

void cargar_cursos(int*codigos, char***&cursos, const char* nombre_archivo) {
    ifstream input(nombre_archivo, ios::in);
    if (not input.is_open()) {
        cout << "El archivo " << nombre_archivo << " no se puede abrir" << endl;
        exit(1);
    }
    int n_alumnos = 0;
    int codigo_alumno = 0;
    while (codigos[n_alumnos])n_alumnos++;
    int arr_n_cursos[n_alumnos]{};
    //reservamos memoria a primer nivel cursos
    cursos = new char**[n_alumnos + 1] {};
    //Crear los buffers
    for (int i = 0; i < n_alumnos; i++)
        cursos[i] = new char*[50] {};

    while (true) {
        input>>codigo_alumno;
        if (input.eof())break;
        input.get();
        indice = buscar_alumno(codigo_alumno, codigos, n_alumnos);
        if (indice != -1)
            colocar_curso(input, cursos[indice], arr_n_cursos[indice]);
    }
    //recortar los espacios q no han sido utilizados
    for (int i = 0; i < n_alumnos; i++)
        recortar(cursos[i], arr_n_cursos[i]);
}
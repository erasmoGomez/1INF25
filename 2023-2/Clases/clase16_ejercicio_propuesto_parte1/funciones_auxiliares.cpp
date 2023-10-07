/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <iostream>
#include <fstream>
#include <cstring>
#include "funciones_auxiliares.hpp"
using namespace std;

#define MAX_EVENTOS 50

void guardar_buffers() {
    buffer_codigos[n_datos] = codigo;
    buffer_fechas[n_datos] = fecha;
    buffer_titulos[n_datos] = titulo;
    buffer_salones[n_datos] = salon;
    buffer_aforos[n_datos] = aforo;
}

void asignar_exacta() {
    codigos = new int[n_datos] {
    };
    fechas = new int[n_datos] {
    };
    titulos = new char*[n_datos] {
    };
    salones = new char*[n_datos] {
    };
    aforos = new int[n_datos] {
    };
    for (int i = 0; i < n_datos; i++) {
        codigos[i] = buffer_codigos[i];
        fechas[i] = buffer_fechas[i];
        titulos[i] = buffer_titulos[i];
        salones[i] = buffer_salones[i];
        aforos[i] = buffer_aforos[i];
    }
    
}

void cargar_eventos(const char* file_name, int *&codigos, int *&fechas,
        char **&titulos, char **&salones, int *&aforos) {
    ifstream input(file_name, ios::in);
    //Agregar validacion
    int buffer_codigos[MAX_EVENTOS]{}, buffer_fechas[MAX_EVENTOS]{};
    int buffer_aforos[MAX_EVENTOS]{};
    char *buffer_titulos[MAX_EVENTOS]{}, *buffer_salones[MAX_EVENTOS]{};
    int n_datos = 0;
    int codigo, fecha, aforo;
    char *titulo, *salon, buffer[100];
    while (true) {
        lectura_evento(input, codigo, fecha, titulo, salon, aforo);
        if (input.eof())break;
        guardar_buffers(buffer_codigos, buffer_fechas, buffer_titulos,
                buffer_salones, buffer_aforos, codigo, fecha, titulo,
                salon, aforo, n_datos);
    }
    n_datos++;
    asignacion_exacta(codigos, fechas, titulos, salones, aforos,
                      buffer_codigos, buffer_fechas, buffer_titulos,
                      buffer_salones, buffer_aforos, n_datos);
    input.close();
    
}

void cambiar_int(int *arr, int i, int j){
    int aux;
    aux = arr[i];
    arr[i] = arr[j];
    arr[j] = aux;
}

void cambiar_char(char ** arr, int i, int j){
    char* aux;
    aux = arr[i];
    arr[i] = arr[j];
    arr[j] = aux;
}

void ordernar_datos(int *codigos, int *fechas, char **titulos, char **salones,
                    int *aforos, int izq, int der){
    int limite;
    if(izq>=der) return;
    cambiar_int(codigos, izq, (izq + der)/2);
    cambiar_int(fechas, izq, (izq + der)/2);
    cambiar_char(titulos, izq, (izq + der)/2);
    cambiar_char(salones, izq, (izq + der)/2);
    cambiar_int(aforos, izq, (izq + der)/2);
    limite = izq;
    for(int i=izq+1; i<=der; i++)
        if(codigos[izq]>codigos[i]){
            ++limite;
            cambiar_int(codigos, limite, i);
            cambiar_int(fechas, limite, i);
            cambiar_char(titulos, limite, i);
            cambiar_char(salones, limite, i);
            cambiar_int(aforos, limite, i);
        }
    cambiar_int(codigos, izq, limite);
    cambiar_int(fechas, izq, limite);
    cambiar_char(titulos, izq, limite);
    cambiar_char(salones, izq, limite);
    cambiar_int(aforos, izq, limite);
    ordernar_datos(codigos, fechas, titulos, salones, aforos, izq, limite-1);
    ordernar_datos(codigos, fechas, titulos, salones, aforos, limite+1, der);
}

void ordenar_eventos(int *codigos, int *fechas, char **titulos, char **salones, int *aforos){
    //Ordenados en base codigos
    int n_datos = 0;
    for(n_datos; codigos[n_datos]; n_datos++);
    int izq =0, der = n_datos-1;
    ordenar_datos(codigos, fechas, titulos, salones, aforos, izq, der, n_datos);
    
}
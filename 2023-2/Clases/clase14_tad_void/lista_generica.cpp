/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "lista_generica.hpp"

enum registro_nodo {
    DATO, SIGUIENTE
};

void insertar_lista(void *&_lista, void *dato, int (*cmp)(const void*, const void*)) {
    void **lista = (void**) _lista;
    void **anterior = nullptr;
    void **nodo;
    nodo = new void*[2];
    nodo[DATO] = dato;
    while (lista) {
        if (cmp(lista[DATO], dato) > 0)break;
        anterior = lista;
        lista = (void**) lista[SIGUIENTE];
    }
    nodo[SIGUIENTE] = lista;
    if (anterior == nullptr) _lista = nodo;
    else anterior[SIGUIENTE] = nodo;
}

void crear_lista(const char *nombre_archivo, void *&lista, void* (*lee)(ifstream &),
        int (*cmp)(const void*, const void*)) {
    void *dato;
    ifstream input(nombre_archivo, ios::in);
    lista = nullptr;
    while (true) {
        dato = lee(input);
        if (input.eof())break;
        insertar_lista(lista, dato, cmp);
    }
}

void imprimir_lista(const char* nombre_archivo, void *_lista, void (*imprime)(void*, ofstream&)) {
    void **lista = (void**) _lista;
    ofstream output(nombre_archivo, ios::out);
    while (lista) {
        imprime(lista[DATO], output);
        lista = (void**) lista[SIGUIENTE];
    }
    output << endl;
}

void eliminar_lista(void *_lista, void (*elimina)(void*)) {
    void **lista = (void**) _lista, **sale;
    while (lista) {
        sale = lista;
        lista = (void**) (lista[SIGUIENTE]);
        elimina(sale[DATO]); //Elimamos el registro
        delete sale; //Eliminamos el nodo
    }
}


/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   lista.hpp
 * Author: erasmog
 *
 * Created on June 27, 2023, 9:06 PM
 */

#ifndef LISTA_HPP
#define LISTA_HPP

#include "nodo.hpp"
#include <fstream>
using namespace std;

template<typename T>class Nodo;

template<typename T>
class Lista {
private:
    class Nodo<T> *lista;
public:

    Lista() {
        lista = nullptr;
    }
    virtual ~Lista();
    void crea(const char*);
    void insertar(const T&);
    void imprimir(const char*);
};

template<typename T>
Lista<T>::~Lista() {
    class Nodo<T>*sale;
    while (lista) {
        sale = lista;
        lista = lista->sig;
        delete sale;
    }
}

template<typename T>
void Lista<T>::crea(const char*nombArch) {
    ifstream arch(nombArch, ios::in);
    if (not arch.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo " << nombArch << endl;
        exit(1);
    }
    T dato;
    while (true) {
        arch>>dato;
        if (arch.eof())break;
        insertar(dato);
    }
}

template<typename T> 
void Lista<T>::insertar(const T&dato) {
    class Nodo<T> *p = lista, *ant = nullptr, *nuevo;
    nuevo = new class Nodo<T>;
    nuevo->dato = dato;
    while (p) {
        if (p->dato > dato) break;
        ant = p;
        p = p->sig;
    }
    nuevo->sig = p; //Insercion
    if (ant != nullptr) ant->sig = nuevo;
    else lista = nuevo;
}

template<typename T>
void Lista<T>::imprimir(const char*nombArch) {
    ofstream arch(nombArch, ios::out);
    if (not arch.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo " << nombArch << endl;
        exit(1);
    }
    class Nodo<T> *p = lista;
    while (p) {
        arch << p->dato << endl;
        p = p->sig;
    }
}

#endif /* LISTA_HPP */


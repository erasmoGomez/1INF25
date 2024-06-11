/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Lista.cpp
 * Author: Erasmo G. Montoya
 * 
 * Created on June 11, 2024, 9:25 AM
 */

#include <valarray>

#include "Lista.hpp"

Lista::Lista() {
    lista = nullptr;
}

Lista::Lista(const Lista& orig) {
}

Lista::~Lista() {
}

void Lista::crear(){
    ifstream input("heroes_dataset_1.csv", ios::in);
    class Heroe h;
    while(true){
        input>>h;
        if(input.eof())break;
        insertar_elemento(h);
    }
}

void Lista::insertar_elemento(const class Heroe&h){
    NodoLista *rec = lista;
    NodoLista *ant = nullptr;
    NodoLista *nuevo;
    
    nuevo = new class NodoLista;
    nuevo->dato = h; //Aca hace sobrecarga
    
    while(rec){
        if(rec->dato>h) break; //Aca hacer sobrecarga
        ant = rec; //No hacer sobrecarga x q son punteros XD
        rec = rec->sig;
    }
    nuevo->sig = rec;
    if(ant!=nullptr)
        ant->sig = nuevo;
    else
        lista = nuevo;
}   

void Lista::imprimir(){
    ofstream out("reporte.txt", ios::out);
    imprime_recursivo(lista, out);
}

void Lista::imprime_recursivo(NodoLista*ptr, ofstream&out){
    if(ptr == nullptr) return;
    out<<ptr->dato;
    imprime_recursivo(ptr->sig, out);
}
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Lista.cpp
 * Author: ASUS
 * 
 * Created on October 31, 2023, 8:57 AM
 */

#include "Lista.hpp"
using namespace std;
Lista::Lista() {
    lista = nullptr;
}

Lista::Lista(const Lista& orig) {
}

Lista::~Lista() {
}

void Lista::crear(){
    ifstream input("heroes.csv",ios::in);
    class hero h;
    while(true){
        input>>h;
        if(input.eof())break;
        // Proceso de insercion o construcion del TAD
        insertar_elemento(h);
    }
}

void Lista::insertar_elemento(const class hero &h){
    class Node *ptr = lista;
    class Node *ant = nullptr;
    class Node *nuevo;
    
    nuevo = new class Node;
    nuevo->dato = h;
    while(ptr){
        if(ptr->dato>h) break;
        ant = ptr;
        ptr = ptr->sig;
    }
    nuevo->sig = ptr;
    if(ant!=nullptr) ant->sig = nuevo;
    else lista = nuevo;
}

void Lista::imprimir() {
    ofstream out("reporte.txt", ios::out);
    class Node *ptr = lista;
    out<<"Heroes en la lista"<<endl;
    out<<left<<setw(5)<<"Code"<<left<<setw(15)<<"Name"<<right<<setw(10)<<"ATT"<<endl;
    
    out<<right<<setw(30)<<setfill('=')<<""<<endl;
    out<<setfill(' ');
    
    while(ptr){
        out<<ptr->dato;
        ptr = ptr->sig;
    }
    out<<endl;
    
}

void Lista::imprimir_recursivo(){
    ofstream out("reporte_r.txt", ios::out);
    imprime_recursivo(out, lista);
}

void Lista::imprime_recursivo(ofstream &out, class Node *ptr){
    if(ptr == nullptr) return;
    imprime_recursivo(out, ptr->sig);
    out<<ptr->dato;
}
//
// Created by erasmo on 6/10/26.
//

#include "EquipoLista.hpp"

EquipoLista::EquipoLista() {
    lista = nullptr;
}

EquipoLista::EquipoLista(const EquipoLista &orig) {
}

EquipoLista::~EquipoLista() {
}

void EquipoLista::crear(const char * file_name) {
    ifstream input(file_name, ios::in);

    while(true){
        class Personaje p;
        input>>p;
        if(input.eof())break;
        insertar(p);
    }
}

void EquipoLista::insertar(const Personaje & p) {
    class NodoLista* recorrido = lista;
    class NodoLista* anterior = nullptr;
    class NodoLista* nuevo;

    //Crear el nodo nuevo
    nuevo = new class NodoLista;
    nuevo->dato = p; // Llama a la sobrecarga del = q ya se hizo

    while(recorrido){
        if(recorrido->dato > p) break; // h1 > h
        anterior = recorrido;
        recorrido = recorrido->sig;
    }
    nuevo->sig = recorrido;
    if(anterior!=nullptr)
        anterior->sig = nuevo;
    else
        lista = nuevo;
}

// Estructura Nodal :> tiene nodos consecutivos
// si yo imprimo cabeza(L) - recursivo imprima el resto (sig).
void EquipoLista::imprimir(const char *nombre_archivo) {
    ofstream output(nombre_archivo, ios::out);
    imprimir_recursivo(lista, output); //Esta funcion tiene que ser PRIVATE
}

void EquipoLista::imprimir_recursivo(class NodoLista* ptr, ofstream& output){
    if(ptr == nullptr) return; //Caso Base
    output<<ptr->dato; // Imprimimos la Cabeza
    imprimir_recursivo(ptr->sig, output); // Llamamos a la recursiva con el resto
}
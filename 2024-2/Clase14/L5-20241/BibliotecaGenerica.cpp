/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "BibliotecaGenerica.hpp"

void generalista(void*&pedidos) {
    void**lista = new void*[2] {
    };
    //    lista[0] = nullptr;
    //    lista[1] = nullptr;
    pedidos = lista;
}

bool listavacia(void *pedidos) {
    void**lista = (void**) pedidos;
    return lista[FIRST] == nullptr and lista[LAST] == nullptr;
}

void insertar(void* pedidos, void *dato) {
    void**lista = (void**) pedidos;
    void**nuevo = new void*[2] {
    };
    void **ultimo;

    nuevo[DATO] = dato; // Llenando el nodo
    nuevo[SIGUIENTE] = nullptr;
    if (listavacia(pedidos)) {
        lista[FIRST] = nuevo;
        lista[LAST] = nuevo;
    } else {
        ultimo = (void**) lista[LAST];
        ultimo[SIGUIENTE] = nuevo;
        lista[LAST] = nuevo;
    }
}

void crealista(void *&pedidos, void *(*lee)(ifstream &), const char *nom) {
    void*dato;
    ifstream input(nom, ios::in);
    if (not input.is_open()) {
        cout << "No se encontro el archivo " << nom << endl;
        exit(1);
    }
    generalista(pedidos); //Su primera funcion relacionada a LISTAS
    while (true) {
        dato = lee(input);
        if (input.eof())break;
        insertar(pedidos, dato);
    }
}

void imprimelista(void *pedidos, void (*imprime)(ofstream &, void *), const char *nom) {
    void*dato, **recorrido;
    void **lista = (void**) pedidos;
    ofstream output(nom, ios::out);
    if (not output.is_open()) {
        cout << "No se encontro el archivo " << nom << endl;
        exit(1);
    }
    recorrido = (void**) lista[FIRST];
    while (recorrido) {
        dato = recorrido[DATO];
        imprime(output, dato);
        recorrido = (void**) recorrido[SIGUIENTE];
    }
}

void *quitalista(void *pedidos){
    void**lista = (void**)pedidos, **nodo, *dato;
    if(listavacia(pedidos)) return nullptr;
    nodo = (void**)lista[FIRST];
    dato = nodo[DATO];
    lista[FIRST] = nodo[SIGUIENTE];
    delete nodo;
    if (not lista[FIRST])
        lista[LAST] = nullptr;
    return dato;
}

void combinalista(void *pedidos1, void *pedidos2, void *&listafinal, int (*cmp)(void *, void *)) {
    void**lista1 = (void**) pedidos1, **cabeza1;
    void**lista2 = (void**) pedidos2, **cabeza2;
    void* nuevo_final, *dato1, *dato2;
    int comparacion = 0;
    generalista(listafinal);
    while (not listavacia(pedidos1) and not listavacia(pedidos2)) {
        cabeza1 = (void**) lista1[FIRST];
        cabeza2 = (void**) lista2[FIRST];
        dato1 = cabeza1[DATO];
        dato2 = cabeza2[DATO];
        comparacion = cmp(dato1, dato2);
        if (comparacion > 0) {
            nuevo_final = quitalista(pedidos2);
        } else if (comparacion < 0) {
            nuevo_final = quitalista(pedidos1);
        } else {
            nuevo_final = quitalista(pedidos1);
            nuevo_final = quitalista(pedidos2);
        }
        insertar(listafinal, nuevo_final);
    }
    while (not listavacia(pedidos1)) {
        nuevo_final = quitalista(pedidos1);
        insertar(listafinal, nuevo_final);
    }
    while (not listavacia(pedidos2)) {
        nuevo_final = quitalista(pedidos2);
        insertar(listafinal, nuevo_final);
    }
}

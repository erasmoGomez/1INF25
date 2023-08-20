/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "funciones.hpp"

//Definicion de la estructura lista simplemente enlazada

enum Reg {
    DATO, SIG
};

enum Reg2 {
    CODIGO, NOMBRE, SUELDO
};

void crear_lista(ifstream &arch, void *&lista, void*(*lee)(ifstream &)) {
    //Crear nuevo dato
    lista = nullptr;
    void* dato;
    while (1) {
        dato = lee(arch);
        if (dato == nullptr) break;
        insertar_lista(lista, dato); //Forma1
        //insertar_lista_ordenado(lista, dato, cmp); //Forma2
    }
}

void crear_lista(ifstream &arch, void *&lista, void*(*lee)(ifstream &), int(*cmp)(const void*, const void*)){
    //Crear nuevo dato
    lista = nullptr;
    void* dato;
    while (1) {
        dato = lee(arch);
        if (dato == nullptr) break;
        insertar_lista(lista, dato); //Forma1
        //insertar_lista_ordenado(lista, dato, cmp); //Forma2
    }
}

void * leer_entero(ifstream &arch) {
    int dato, *d;
    arch>>dato;
    if (arch.eof()) return nullptr;
    d = new int;
    *d = dato;
    return d;
}

void insertar_lista(void *&lista, void *dato) {
    void **ls = (void **) lista;
    void **nodo;
    void **anterior = nullptr;

    nodo = new void*[2]; //Definimos el nodo de la lista
    nodo[DATO] = dato;
    nodo[SIG] = nullptr;

    while (ls) {
        anterior = ls;
        //seguir recorriendo
        ls = (void**) ls[SIG];
    }

    nodo[SIG] = ls;
    if (anterior == nullptr) // No hay elementos en la lista
        lista = nodo;
    else
        anterior[SIG] = nodo; // Si hay elementos en la lista

}

void insertar_lista_ordenado(void *&lista, void *dato, int(*comp)(const void*, const void*)) {
    void **ls = (void **) lista;
    void **nodo;
    void **anterior = nullptr;

    nodo = new void*[2]; //Definimos el nodo de la lista
    nodo[DATO] = dato;
    nodo[SIG] = nullptr;

    while (ls) {
        if (comp(ls[DATO], dato) > 0) break;
        anterior = ls;
        //seguir recorriendo
        ls = (void**) ls[SIG];
    }

    nodo[SIG] = ls;
    if (anterior == nullptr) // No hay elementos en la lista o la p[osicion del elemento esta al inicio
        lista = nodo;
    else
        anterior[SIG] = nodo; // Si hay elementos en la lista

}

void * leer_registro(ifstream &arch) {
    int *codigo, code;
    double *sueldo;
    char *nombre, buffer[100];
    void **registro;

    arch>>code;
    if (arch.eof()) return nullptr;
    //if(code%2==0) return nullptr;
    codigo = new int;
    *codigo = code;
    arch.get();

    arch.getline(buffer, 100, ',');
    nombre = new char[strlen(buffer) + 1];
    strcpy(nombre, buffer);

    sueldo = new double;
    arch>>*sueldo;

    registro = new void*[3];
    registro[CODIGO] = codigo;
    registro[NOMBRE] = nombre;
    registro[SUELDO] = sueldo;

    return registro;
}

int cmp_registro_multi_criterio(const void* a, const void* b) {
    void **reg_a = (void**) a;
    void **reg_b = (void**) b;

    int *codigo_reg_a = (int *) reg_a[CODIGO];
    double *sueldo_reg_a = (double *) reg_a[SUELDO];
    char *nombre_reg_a = (char *) reg_a[NOMBRE];

    int *codigo_reg_b = (int *) reg_b[CODIGO];
    double *sueldo_reg_b = (double *) reg_b[SUELDO];
    char *nombre_reg_b = (char *) reg_b[NOMBRE];

    if (strcmp(nombre_reg_a, nombre_reg_b) == 0 and *sueldo_reg_a == *sueldo_reg_b) {
        return *codigo_reg_a - *codigo_reg_b;
    }
    if (strcmp(nombre_reg_a, nombre_reg_b) == 0) {
        return *sueldo_reg_a - *sueldo_reg_b;
    } else
        return strcmp(nombre_reg_b, nombre_reg_a);

}

void eliminar_lista(void *lista_reg, void(*eliminar_registro)(void*)) {
    void ** ls = (void**) lista_reg;
    void ** node_to_delete;
    while (ls) {
        node_to_delete = ls;
        ls = (void**) (ls[SIG]);
        eliminar_registro(node_to_delete[DATO]); //Eliminar elementos dentro de cada dato
        delete node_to_delete;
    }

}

void eliminar_registro(void* reg) {
    void** r = (void**) reg;
    int* codigo = (int*) r[CODIGO];
    char* nombre = (char*) r[NOMBRE];
    double* sueldo = (double*) r[SUELDO];
    delete codigo;
    delete nombre;
    delete sueldo;
}

void imprimir_lista(void *lista, void (*imprime)(void*)) {
    void **ls = (void**) lista;
    while (ls) {
        imprime(ls[DATO]);
        ls = (void**) (ls[SIG]);
    }
    cout<<endl;
}

void imprimir_registro(void* reg) {
    void** r = (void**) reg;
    int* codigo = (int*) r[CODIGO];
    char* nombre = (char*) r[NOMBRE];
    double* sueldo = (double*) r[SUELDO];
    
    cout.precision(2);
    cout<<fixed;
    cout<<left<<setw(10)<<*codigo;
    cout<<setw(50)<<nombre;
    cout<<right<<setw(10)<<*sueldo<<endl;
}

void imprimir_entero(void* dato) {
    int* numero = (int*) dato;
    
    cout<<left<<setw(10)<<*numero<<endl;
}
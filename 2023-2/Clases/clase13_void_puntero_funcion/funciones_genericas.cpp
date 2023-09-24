/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "funciones_genericas.hpp"

int funcion_comparacion_codigos(const void* a, const void* b){
    //Aterrizamos a la persona
    void **ai = (void **)a;
    void **bi = (void **)b;
    
    void **registro_a = (void**)(ai[0]);
    void **registro_b = (void**)(*bi);
    
    int *codigo_a = (int *)registro_a[CODIGO];
    int *codigo_b = (int *)registro_b[CODIGO];
    //cout<<*codigo_a << "    "<<*codigo_b<<endl;
    return *codigo_b - *codigo_a; //descendente
    //return *codigo_a - *codigo_b; ascendente
}

int funcion_comparacion_nombres(const void* a, const void* b){
    //Aterrizamos a la persona
    void **ai = (void **)a;
    void **bi = (void **)b;
    
    void **registro_a = (void**)(ai[0]);
    void **registro_b = (void**)(*bi);
    
    char *nombre_a = (char *)registro_a[NOMBRE];
    char *nombre_b = (char *)registro_b[NOMBRE];
    //cout<<nombre_a << "    "<<nombre_b<<endl;
    //return 0;
    return strcmp(nombre_a, nombre_b); //ascendente
    //return *codigo_a - *codigo_b; descendente
}

void cambiar(void ** arr, int i, int j){
    void* aux;
    aux = arr[i];
    arr[i] = arr[j];
    arr[j] = aux;
}

void ordenar_personal(void *personal, int izq,int der, int (*fcmp)(const void*, const void*)){
    void **arreglo = (void**)personal;
    int limite;
    if(izq>=der) return;
    cambiar(arreglo, izq, (izq + der)/2);
    limite = izq;
    for(int i=izq+1; i<der; i++)
        if(fcmp(arreglo[izq],arreglo[i])>0)
            cambiar(arreglo, ++limite, i);
    cambiar(arreglo, izq,limite);
    ordenar_personal(arreglo, izq, limite-1, fcmp);
    ordenar_personal(arreglo, limite+1, der, fcmp);
}

int funcion_comparacion_propia_codigos(const void *a, const void *b){
    //Aterrizamos a la persona
    void **registro_a= (void **)a;
    void **registro_b = (void **)b;
    
    int *codigo_a = (int*)registro_a[CODIGO];
    int *codigo_b = (int*)registro_b[CODIGO];
    //cout<<*codigo_a<<"     "<<*codigo_b<<endl;
    return 0;
}
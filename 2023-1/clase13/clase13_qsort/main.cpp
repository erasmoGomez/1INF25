/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: erasmog
 *
 * Created on May 23, 2023, 8:44 AM
 */

#include "funciones.hpp"
/*
 * 
 */
int main(int argc, char** argv) {
//    int arr[50] = {20082060, 20190388, 20172844, 20203564, 20201948};
//    int nd = 5;
//    qsort(arr, nd, sizeof(int), cmp);
//    for(int i = 0; i<nd; i++){
//        cout<<arr[i]<<endl;
//    }
    
    //cout<<cmp_str("apa","ala")<<endl;
//    char ** personas;
//    int n = 0;
//    leer_datos_str(personas, n);
//    cout<<"Imprimir Desordenado"<<endl;
//    imprimir_personas(personas,n);
//    qsort(personas,n,sizeof(char*),cmp_str);
//    cout<<"Imprimir Ordenado"<<endl;
//    imprimir_personas(personas,n);
    
    void * personas;
    int n = 0;
    leer_datos_void(personas, n);
    imprimir_datos_void(personas, n);
    qsort(personas,n,sizeof(void *),cmp_nombres_void);
    cout<<"Imprimir Ordenado - Nombre"<<endl;
    imprimir_datos_void(personas, n);
    
    qsort(personas,n,sizeof(void *),cmp_sueldos_void);
    cout<<"Imprimir Ordenado - Sueldo"<<endl;
    imprimir_datos_void(personas, n);
    
    qsort(personas,n,sizeof(void *),cmp_codigo_void);
    cout<<"Imprimir Ordenado - Codigo"<<endl;
    imprimir_datos_void(personas, n);
    
    qsort(personas,n,sizeof(void *),cmp_multicriterio_void);
    cout<<"Imprimir Ordenado - MultiCriterio"<<endl;
    imprimir_datos_void(personas, n);
    return 0;
}


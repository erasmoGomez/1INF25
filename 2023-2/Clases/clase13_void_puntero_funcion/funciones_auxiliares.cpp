/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "funciones_genericas.hpp"


void* leer_registro(ifstream &input){
    void **registro;
    int codigo, *ptr_codigo;
    double sueldo, *ptr_sueldo;
    char buffer_nombre[100], *ptr_nombre;
    input>>codigo;
    if(input.eof()) return nullptr;
    input.get();
    input.getline(buffer_nombre, 100, ',');
    input>>sueldo;
    
    ptr_codigo = new int;
    *ptr_codigo = codigo;
    
    ptr_sueldo = new double;
    *ptr_sueldo = sueldo;
    
    ptr_nombre = new char[strlen(buffer_nombre)+1];
    strcpy(ptr_nombre,buffer_nombre);
    
    registro = new void*[3];
    registro[CODIGO] = ptr_codigo;
    registro[NOMBRE] = ptr_nombre;
    registro[SUELDO] = ptr_sueldo;
    
    return registro;
}

void leer_datos_personal(void *&personal, int &n_datos){
    ifstream input("personal.csv", ios::in);
    void *buffer_personal[500];
    void *persona;
    void **personal_aux_void; //Este areglo de punteros void me sirve para guardar los datos del buffer
    n_datos = 0;
    while(1){
        persona = leer_registro(input);
        if(input.eof())break;
        buffer_personal[n_datos] = persona;
        n_datos++;
    }
    personal_aux_void = new void*[n_datos];
    for(int i=0; i<n_datos;i++)
        personal_aux_void[i] = buffer_personal[i];
    personal = personal_aux_void;
}

void imprimir_registro(void *persona){
    void **registro = (void **)persona;
    int * codigo = (int*)registro[CODIGO];
    double *sueldo = (double *)registro[SUELDO];
    char *nombre = (char *)registro[NOMBRE];
    cout.precision(2);
    cout<<fixed;
    cout<<left<<setw(10)<<*codigo;
    cout<<setw(45)<<nombre;
    cout<<right<<setw(10)<<*sueldo<<endl;
}

void imprimir_datos(void *personal, int n_datos){
    void **personas = (void**)personal;
    for(int i = 0; i<n_datos;i++)
        imprimir_registro(personas[i]);
}
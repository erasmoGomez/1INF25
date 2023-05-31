/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "auxiliar.hpp"
enum Registro {CODIGO, NOMBRE, SUELDO};

void *leerReg(ifstream&arch) {
    void **r;
    int *codigo, cod;
    char*nombre, buff[100];
    double*sueldo;

    arch>>cod;
    if (arch.eof()) return nullptr;
    codigo = new int;
    *codigo = cod;
    arch.get(); // Sacamos la coma
    arch.getline(buff, 100, ',');
    nombre = new char[strlen(buff) + 1];
    strcpy(nombre, buff);
    sueldo = new double;
    arch>>*sueldo;

    r = new void*[3];
    r[CODIGO] = codigo;
    r[NOMBRE] = nombre;
    r[SUELDO] = sueldo;

    return r;
}

void leer_datos_void(void *&personas, int &n) {
    ifstream arch("personal.csv", ios::in);
    if (!arch) {
        cout << "ERROR: No se pudo abrir el archivo personal.csv" << endl;
        exit(1);
    }
    void *buffer[500], **per, *p;
    n = 0;
    while (1) {
        p = leerReg(arch);
        if (p == nullptr) break;
        buffer[n] = p;
        n++;
    }
    per = new void*[n];
    for (int i = 0; i < n; i++)
        per[i] = buffer[i];
    personas = per;
}

void imprimir_registro_void(void* reg){
    void ** persona = (void**)reg;
    int* codigo = (int *)persona[CODIGO];
    char* nombre = (char*)persona[NOMBRE];
    double* sueldo = (double*)persona[SUELDO];
    cout.precision(2);
    cout<<fixed;
    cout<<left<<setw(10)<<*codigo<<setw(45)<<nombre<<right<<setw(10)<<*sueldo<<endl;
}

void imprimir_datos_void(void *personas, int n){
    void **persona = (void**)personas;
    for(int i = 0; i<n; i++)
        imprimir_registro_void(persona[i]);
}

int cmp_codigo_void(const void* a, const void* b){
    void **pa = (void **) a;
    void **pb = (void **) b;
    //segundo casteo para atterrizar en el arreglo con el int*
    
    int* inta = (int*)pa[CODIGO];
    int* intb = (int*)pb[CODIGO];
    return *inta - *intb;
}
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "funciones.hpp"

enum Registro {CODIGO, NOMBRE, SUELDO};

int cmp(const void* a, const void* b) {
    int *pa = (int *) a;
    int *pb = (int *) b;
    return *pa - *pb;
}

int cmp_str(const void* a, const void* b) {
    int result = 0;
//    char *pa = *(char **) a;
//    char *pb = *(char **) b;
    char **pa = (char **)a;
    char **pb = (char **)b;
    cout<<*pa<<"   "<<*pb<<endl;
    result = strlen(*pa)- strlen(*pb);
    return result;
}

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

void imprimir_personas(char** personas, int n){
    for(int i=0;i<n;i++){
        cout<<personas[i]<<endl;
    }
    
}

void leer_datos_str(char **& personas, int &n){
    //Arreglo de cadenas caracteres
    char *buffer[100],cadena[20], *nombre;
    ifstream arch_input("Personas.txt", ios::in);
    while(1){
        arch_input>>cadena;
        if(arch_input.eof()) break;
        nombre  = new char[strlen(cadena)+1];
        strcpy(nombre,cadena);
        buffer[n] = nombre;
        n++;
    }
    personas = new char*[n];
    //personas = buffer; grave error de concepto
    for(int i = 0; i<n;i++)
        personas[i] = buffer[i];
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

int cmp_nombres_void(const void* a, const void* b){
    void **pa = (void **) a;
    void **pb = (void **) b;
    
    //segundo casteo para atterrizar en el arreglo con el char*
    
    void **paa = (void **)(*pa);
    void **pbb = (void **)(*pb);
    
    //tercer castero para atterizar ahora si en char*
    
    char* stra = (char*)paa[NOMBRE];
    char* strb = (char*)pbb[NOMBRE];
    
    return strcmp(stra,strb);
}

int cmp_sueldos_void(const void* a, const void* b){
    void **pa = (void **) a;
    void **pb = (void **) b;
    
    //segundo casteo para atterrizar en el arreglo con el char*
    
    void **paa = (void **)(*pa);
    void **pbb = (void **)(*pb);
    
    //tercer castero para atterizar ahora si en double*
    
    double* doublea = (double*)paa[SUELDO];
    double* doubleb = (double*)pbb[SUELDO];
    
    return *doublea - *doubleb;
}

int cmp_codigo_void(const void* a, const void* b){
    void **pa = (void **) a;
    void **pb = (void **) b;
    
    //segundo casteo para atterrizar en el arreglo con el char*
    
    void **paa = (void **)(*pa);
    void **pbb = (void **)(*pb);
    
    //tercer castero para atterizar ahora si en int*
    
    int* inta = (int*)paa[CODIGO];
    int* intb = (int*)pbb[CODIGO];
    
    return *inta - *intb;
}

int cmp_multicriterio_void(const void* a, const void* b){
    void **pa = (void **) a;
    void **pb = (void **) b;
    
    //segundo casteo para atterrizar en el arreglo con el char*
    
    void **paa = (void **)(*pa);
    void **pbb = (void **)(*pb);
    
    //tercer castero para atterizar ahora si en int*
    
    int* inta = (int*)paa[CODIGO];
    int* intb = (int*)pbb[CODIGO];
    
    double* doublea = (double*)paa[SUELDO];
    double* doubleb = (double*)pbb[SUELDO];
    
    char* stra = (char*)paa[NOMBRE];
    char* strb = (char*)pbb[NOMBRE];
    
    if(*inta==*intb and strcmp(stra, strb)==0){
        return *doublea - *doubleb;//Ascending
    }
    
    if(*inta==*intb){
        return strcmp(strb, stra);//Descending
    }
    else
        return *inta-*intb;//Ascending
}

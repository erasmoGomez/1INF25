/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "funcines_genericas.hpp"

void incrementar_memoria(void **&alumnos, int &nd, int &cap) {
    void ** aux;
    cap += INCREMENTO;
    if (alumnos == nullptr) {
        alumnos = new void*[cap] {
        };
        nd = 1;
    } else {
        aux = new void*[cap] {
        };
        for (int i = 0; i < nd; i++)
            aux[i] = alumnos[i];
        delete alumnos;
        alumnos = aux;
    }
}

char *leer_cadena(ifstream &arch, char car) {
    char cadena[60], *cad;
    arch.getline(cadena, 60, car);
    cad = new char [strlen(cadena) + 1];
    strcpy(cad, cadena);
    return cad;
}

void* leer_registro(ifstream& input) {
    //20196975,Hijar Pairazaman Jenny Delicia
    void**reg;
    int *codigo, cod;
    char* nombre;
    input>>cod;
    if (input.eof())return nullptr;
    codigo = new int;
    *codigo = cod;
    input.get();
    nombre = leer_cadena(input);

    reg = new void*[3] {
    };
    reg[CODIGO] = codigo;
    reg[NOMBRE] = nombre;
    return reg;
}

void cargar_alumnos(void *&alumnos, const char *nombre_archivo) {
    ifstream input(nombre_archivo, ios::in);
    int cantidad = 0, capacidad = 0;
    void** alumnos_arr, *registro;
    alumnos_arr = nullptr;
    while (true) {
        registro = leer_registro(input);
        if (input.eof())break;
        if (cantidad == capacidad) incrementar_memoria(alumnos_arr, cantidad, capacidad);
        alumnos_arr[cantidad - 1] = registro;
        cantidad++;
    }
    alumnos = alumnos_arr;
}

void probar_carga(void *alumnos, const char* archivo_nombre) {
    ofstream output(archivo_nombre, ios::out);
    void **alumnos_recorrido = (void**) alumnos;
    for (int i = 0; alumnos_recorrido[i]; i++)
        imprimir_alumno(alumnos_recorrido[i], output);
}

void imprimir_alumno(void *alumno, ofstream& output) {
    void **registro = (void**) alumno;
    int*ptr_codigo;
    char*ptr_nombre;
    ptr_codigo = (int*) registro[CODIGO];
    ptr_nombre = (char*) registro[NOMBRE];

    output << left << setw(10) << *ptr_codigo;
    output << left << setw(50) << ptr_nombre << endl;
}

void ordenar(void* alumnos) {
    void **alumnos_recorrido = (void**) alumnos;
    int cantidad = 0;
    for (cantidad = 0; alumnos_recorrido[cantidad]; cantidad++);
    //cout<<cantidad<<endl;
    quick_sort(alumnos_recorrido, 0, cantidad-1);
}

void cambiar(void*&alumno1, void*&alumno2){
    void*aux;
    aux = alumno1;
    alumno1 = alumno2;
    alumno2 = aux;
}

void quick_sort(void**alumnos, int izq, int der) {
    int limite;
    int pivote = (izq + der) / 2;
    if (izq >= der)return; //Condicion de parada
    cambiar(alumnos[izq], alumnos[pivote]);
    limite = izq;
    for (int i = izq + 1; i <= der; i++)
        if (comparar_orden(alumnos[i], alumnos[izq]))
            cambiar(alumnos[++limite], alumnos[i]);
    cambiar(alumnos[izq], alumnos[limite]);
    quick_sort(alumnos, izq, limite - 1);
    quick_sort(alumnos, limite + 1, der);
}

bool comparar_orden(void*al1, void*al2){
    void**registro1 = (void**)al1;
    void**registro2 = (void**)al2;
    char *nombre_al1,*nombre_al2;
    int *codigo_al1, *codigo_al2;
    nombre_al1 = (char*)registro1[NOMBRE];
    nombre_al2 = (char*)registro2[NOMBRE];
//    
//    codigo_al1 = (int*)registro1[CODIGO];
//    codigo_al2 = (int*)registro2[CODIGO];
//    
//    bool resultado;
//    if(strcmp(nombre_al1, nombre_al2)<0) or  
//            strcmp(nombre_al1, nombre_al2 == 0 
//            and *codigo_al1<*codigo_al1:
//        resultado == true;
    return strcmp(nombre_al1, nombre_al2)<0;
}
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   funciones_genericas.cpp
 * Author: Erasmo Gomez
 * Description: 
 * Created on April 16, 2025, 4:24 PM
 */

#include "funciones_genericas.hpp"

char* leer_cadena(ifstream& input, char car){
    char cadena[60],*cad;
    input.getline(cadena, 60, car);
    cad = new char[strlen(cadena)+1];
    strcpy(cad, cadena);
    return cad;
}

void* leer_registro(ifstream& input){
    //20196975	Hijar Pairazaman Jenny Delicia
    void** registro;
    int codigo, *ptr_codigo;
    char* nombre;
    input>>codigo;
    if(input.eof()) return nullptr;
    ptr_codigo = new int;
    *ptr_codigo = codigo; // ptr_codigo[0] = codigo;
    input.get();
    nombre = leer_cadena(input, '\n');
    
    //Reserva de memoria
    registro = new void*[4]{};
    registro[CODIGO] = ptr_codigo;
    registro[NOMBRE] = nombre;
    registro[CURSOS] = nullptr;
    registro[PROMEDIO] = nullptr;
    return registro;
}

void incrementar_memoria(void**&alumnos, int&n, int&capacidad){
    void** aux_alumnos;
    capacidad += INCREMENTO;
    if(alumnos == nullptr){
        alumnos = new void*[capacidad]{};
        n = 1;
    } else{
        aux_alumnos = new void*[capacidad]{};
        for(int i = 0; i<n;i++)
            aux_alumnos[i] = alumnos[i];
        delete alumnos;
        alumnos = aux_alumnos;
    }
}

void cargar_alumnos(void*&alumnos, const char*nombre_archivo){
    ifstream input(nombre_archivo, ios::in);
    int cantidad_alumnos = 0, capacidad =0;
    void ** alumnos_arreglo, *registro;
    alumnos_arreglo = nullptr;
    while(true){
        registro = leer_registro(input);
        if(input.eof()) break;
        if(cantidad_alumnos == capacidad) 
            incrementar_memoria(alumnos_arreglo, cantidad_alumnos, capacidad);
        alumnos_arreglo[cantidad_alumnos-1] = registro;
        cantidad_alumnos++;
    }
    alumnos = alumnos_arreglo;
}

bool son_iguales(int codigo, void*alumno){
    void** registro = (void**)alumno;
    int* codigo_ptr = (int*) registro[CODIGO];
    return codigo == *codigo_ptr;
}

int buscar_alumno(int codigo, void** arr_alumnos){
    for(int i=0; arr_alumnos[i]; i++)
        if(son_iguales(codigo, arr_alumnos[i]))return i;
    return -1;
}

void* leer_curso(ifstream &input){
    char* codigo;
    int* nota = new int;
    void **registro = new void*[2];
    codigo = leer_cadena(input, ',');
    input>>*nota;
    registro[CODIGOCURSO] = codigo;
    registro[NOTA] = nota;
    return registro;
}

void aumentar_memoria(void*&cursos, int &n, int&c){
    void **cursos_arreglo = (void**)cursos, **aux;
    c+=INCREMENTO;
    if(cursos_arreglo == nullptr){
        cursos_arreglo = new void*[c];
        n = 1;
    } else{
        aux = new void*[c]{};
        for(int i = 0; i<n; i++)
            aux[i] = cursos_arreglo[i];
        delete cursos_arreglo;
        cursos_arreglo = aux;
    }
    cursos = cursos_arreglo;
}

void agregar_curso(void* curso, void*cursos, int n){
    void ** arr_cursos = (void**)cursos;
    arr_cursos[n] = curso;
}

void colocar_curso(ifstream& input, void*alumno, int& n, int& c){
    void **registro = (void**)alumno;
    void *curso;
    curso = leer_curso(input);
    if(c == n)
        aumentar_memoria(registro[CURSOS], n, c);
    agregar_curso(curso, registro[CURSOS], n - 1);
    n++;
}

void cargar_notas(void*alumnos, const char*nombre_archivo){
    //20189596, MEC289, 17
    ifstream input(nombre_archivo, ios::in);
    void**arr_alumnos = (void**)alumnos;
    int codigo, n_datos[50]{}, cap[50]{}, pos;
    while(true){
        input>>codigo;
        if(input.eof())break;
        input.get();
        pos = buscar_alumno(codigo, arr_alumnos);
        if(pos!=-1){
            colocar_curso(input, arr_alumnos[pos], n_datos[pos], cap[pos]);
        }
        else
            while(input.get()!= '\n');
    }
}

int obtener_nota(void* curso){
    void**registro = (void**)curso;
    int* nota = (int*)registro[NOTA];
    return *nota;
}

void* promedio(void* cursos){
    void** arreglo_cursos = (void**)cursos;
    int suma = 0, cantidad_datos = 0;
    double *promedio = new double;
    for(int i=0; arreglo_cursos[i]; i++){
        suma += obtener_nota(arreglo_cursos[i]);
        cantidad_datos++;
    }
    *promedio = (double)suma/cantidad_datos;
    return promedio;
}

void obtener_promedio(void* alumno){
    void** registro = (void**)alumno;
    registro[PROMEDIO] = promedio(registro[CURSOS]);
}

void calcular_promedio(void* alumnos){
    void**arreglo_alumnos = (void**)alumnos;
    for(int i = 0; arreglo_alumnos[i]; i++)
        obtener_promedio(arreglo_alumnos[i]);
}

void imprimir_alumno(void* alumno, ofstream& output){
    void **registro = (void**)alumno;
    int* ptr_codigo = (int*)registro[CODIGO];
    char* ptr_nombre = (char*)registro[NOMBRE];
    
    output<<left<<setw(10)<<*ptr_codigo;
    output<<left<<setw(50)<<ptr_nombre<<endl;
    
//    if(registro[CURSOS])
//        cout<<"EXISTE"<<endl;
}

void probar_carga(void*alumnos, const char*archivo_nombre){
    ofstream output(archivo_nombre, ios::out);
    void **arreglo_alumnos = (void**)alumnos;
    for(int i=0; arreglo_alumnos[i]; i++)
        imprimir_alumno(arreglo_alumnos[i], output);
}

void cambiar(void*&alumno1, void*&alumno2){
    void*aux;
    aux = alumno1;
    alumno1 = alumno2;
    alumno2 = aux;
}

bool comparar_orden(void *a1, void* a2){
    void**registro1 = (void**)a1;
    void**registro2 = (void**)a2;
    
    char* nombre_a1, *nombre_a2;
    //int* codigo_a1, *codigo_a2;

    nombre_a1 = (char*)registro1[NOMBRE];
    nombre_a2 = (char*)registro2[NOMBRE];
//    int cantidad_cursos_a1, int cantidad_cursos_a2;
//    cantidad_cursos_a1 = calcular_cantidad(registro1[CURSOS]);
//    cantidad_cursos_a2 = calcular_cantidad(registro2[CURSOS]);
//    codigo_a1 = (int*)registro1[CODIGO];
//    codigo_a2 = (int*)registro2[CODIGO];
//    return *codigo_a1<*codigo_a2
    return strcmp(nombre_a1, nombre_a2) < 0;
}

void quick_sort(void** alumnos, int izq, int der){
    int pivote = (izq + der)/2;
    int limite;
    if(izq>=der) return;
    cambiar(alumnos[izq], alumnos[pivote]);
    limite = izq;
    for(int i=izq+1; i<=der; i++)
        if(comparar_orden(alumnos[i], alumnos[izq]))
            cambiar(alumnos[++limite], alumnos[i]);
    cambiar(alumnos[izq], alumnos[limite]);
    quick_sort(alumnos, izq, limite-1);
    quick_sort(alumnos, limite+1, der);
}

void ordenar(void*alumnos){
    void** arreglo_alumnos = (void**)alumnos;
    int cantidad = 0;
    for(cantidad = 0; arreglo_alumnos[cantidad]; cantidad++);
    quick_sort(arreglo_alumnos, 0, cantidad-1);
}
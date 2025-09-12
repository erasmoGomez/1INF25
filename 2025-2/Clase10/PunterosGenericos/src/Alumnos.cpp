//
// Created by Erasmo on 10/09/25.
//

#include "Alumnos.hpp"
char* leer_cadena(ifstream& input, char car) {
    char cadena[60], *cad;
    input.getline(cadena, 60, car);
    cad = new char[strlen(cadena) + 1];
    strcpy(cad, cadena);
    return cad;
}

void* leer_registro(ifstream &input){
    //20196975, Hijar Pairazaman Jenny Delicia
    void** registro;
    int codigo, *ptr_codigo;
    char* nombre;
    input>>codigo;
    if(input.eof())return nullptr;
    ptr_codigo = new int;
    *ptr_codigo = codigo; //ptr_codigo[0]
    input.get();
    nombre = leer_cadena(input, '\n');
    //Reservar memoria
    registro = new void*[4]{};
    registro[CODIGO] = ptr_codigo;
    registro[NOMBRE] = nombre;
    registro[PROMEDIO] = nullptr;
    registro[CURSOS] = nullptr;

    return registro;
}

void incrementar_memoria(void**&arr_alumnos, int& cantidad_alumnos, int& capacidad){
    capacidad += INCREMENTO;
    void ** aux;
    if(arr_alumnos == nullptr){
        arr_alumnos = new void*[capacidad]{};
        cantidad_alumnos = 1;
    }
    else{
        aux = new void*[capacidad]{};
        for(int i=0; i<cantidad_alumnos;i++)
            aux[i] = arr_alumnos[i];
        delete arr_alumnos;
        arr_alumnos = aux;
    }
}

void cargar_alumnos(void *&alumnos, const char *nombre_archivo) {

    ifstream input;
    input.open(nombre_archivo, ios::in);

    //Recorrer alumnos
    void **arr_alumnos;
    void *registro;
    int cantidad_alumnos = 0, capacidad = 0;
    while(true){
        registro = leer_registro(input);
        if(input.eof())break;
        if(capacidad == cantidad_alumnos)
            incrementar_memoria(arr_alumnos, cantidad_alumnos, capacidad);
        arr_alumnos[cantidad_alumnos-1] = registro;
        cantidad_alumnos++;
    }
    alumnos = arr_alumnos;
}

void imprimir_alumno(void* alumno, ofstream &output){
    void **registro = (void**) alumno;
    int* ptr_codigo = (int*) registro[CODIGO];
    char* ptr_nombre = (char*) registro[NOMBRE];
    output<<*ptr_codigo<<endl;
    output<<ptr_nombre<<endl;
}

void prueba_carga_alumnos(void* alumnos, const char*nombre_archivo){
    ofstream output(nombre_archivo, ios::out);
    void **arr_alumnos = (void**)alumnos;
    for(int i=0; arr_alumnos[i]; i++)
        imprimir_alumno(arr_alumnos[i], output);
}

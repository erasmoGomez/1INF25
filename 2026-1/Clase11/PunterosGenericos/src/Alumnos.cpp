//
// Created by Erasmo on 10/09/25.
//

#include "Alumnos.hpp"

#include <iostream>

char *leer_cadena(ifstream &input, char car) {
    char cadena[60];
    input.getline(cadena, 60, car);
    char *cad = new char[strlen(cadena) + 1];
    strcpy(cad, cadena);
    return cad;
}

void *leer_registro(ifstream &input) {
    //378708,SAENZ ARANDA WILMER,23455.6
    int codigo;
    input >> codigo;
    if (input.eof())return nullptr;
    int *ptr_codigo = new int;
    *ptr_codigo = codigo; //ptr_codigo[0]
    input.get();
    char *nombre = leer_cadena(input, ',');
    double monto;
    input >> monto;
    //Reservar memoria
    void **registro = new void *[4]{};
    registro[CODIGO] = ptr_codigo;
    registro[NOMBRE] = nombre;
    registro[PROMEDIO] = nullptr;
    registro[CURSOS] = nullptr;

    return registro;
}

void incrementar_memoria(void **&arr_alumnos, int &cantidad_alumnos, int &capacidad) {
    capacidad += INCREMENTO;
    if (arr_alumnos == nullptr) {
        arr_alumnos = new void *[capacidad]{};
        cantidad_alumnos = 1;
    } else {
        void **aux = new void *[capacidad]{};
        for (int i = 0; i < cantidad_alumnos; i++)
            aux[i] = arr_alumnos[i];
        delete arr_alumnos;
        arr_alumnos = aux;
    }
}

void cargar_alumnos(void *&alumnos, const char *nombre_archivo, int &num_alumnos) {
    ifstream input;
    input.open(nombre_archivo, ios::in);

    //Recorrer alumnos
    void **arr_alumnos = nullptr;
    int capacidad = 0;
    while (true) {
        void *registro = leer_registro(input);
        if (input.eof())break;
        if (capacidad == num_alumnos)
            incrementar_memoria(arr_alumnos, num_alumnos, capacidad);
        arr_alumnos[num_alumnos - 1] = registro;
        num_alumnos++;
    }
    num_alumnos--;
    alumnos = arr_alumnos;
}

void imprimir_alumno(void *alumno, ofstream &output) {
    void **registro = (void **) alumno;
    int *ptr_codigo = (int *) registro[CODIGO];
    char *ptr_nombre = (char *) registro[NOMBRE];
    output << left<<setw(20) << *ptr_codigo;
    output << setw(20) << ptr_nombre << endl;
}

void prueba_carga_alumnos(void *alumnos, const char *nombre_archivo) {
    ofstream output(nombre_archivo, ios::out);
    void **arr_alumnos = (void **) alumnos;
    for (int i = 0; arr_alumnos[i]; i++)
        imprimir_alumno(arr_alumnos[i], output);
}

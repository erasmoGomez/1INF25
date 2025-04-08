/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   funciones.cpp
 * Author: erasmo
 * 
 * Created on April 2, 2025, 4:35 PM
 */

#include "funciones.hpp"

// =============================================================================
// 1. Funciones de Utilidad General
// =============================================================================

char* leer_cadena(ifstream& input, char del) {
    char *nombre, buffer[MAX_CARACTER];
    input.getline(buffer, MAX_CARACTER, del);
    nombre = new char[strlen(buffer) + 1];
    strcpy(nombre, buffer);
    return nombre;
}

int buscar(int *codigos, int codigo) {
    for (int i = 0; codigos[i]; i++)
        if (codigos[i] == codigo)return i;
    return -1;
}

// =============================================================================
// 2. Entrada/Salida de Archivos
// =============================================================================

void imprimir_alumnos(int* codigos, char**nombres, const char*nombre_archivo) {
    ofstream output;
    AperturaDeUnArchivoDeTextosParaEscribir(output, nombre_archivo);
    output << "CODIGOS" << setw(20) << "NOMBRES" << endl;
    for (int i = 0; codigos[i]; i++) {
        output << codigos[i] << setw(100) << nombres[i] << endl;
    }
}

void reporte_cursos(ofstream &output, char**cursos_alumnos) {
    for (int i = 0; cursos_alumnos[i]; i++)
        output << right << setw(15) << cursos_alumnos[i];
    output << endl;
}

void imprimir_alumnos(int* codigos, char**nombres, char***cursos, const char*nombre_archivo) {
    ofstream output;
    AperturaDeUnArchivoDeTextosParaEscribir(output, nombre_archivo);
    output << "CODIGOS" << setw(20) << "NOMBRES" << endl;
    for (int i = 0; codigos[i]; i++) {
        output << codigos[i] << setw(40) << nombres[i] << endl;
        if (cursos[i])
            reporte_cursos(output, cursos[i]);
        else
            output << "No se encontraron cursos" << endl;
    }
}

// =============================================================================
// 3. Lectura y Almacenamiento de Alumnos (memoria dinámica exacta)
// =============================================================================

void leer_datos(ifstream& input, int* buffer_codigos, char**buffer_nombres, int& n_datos) {
    int codigo;
    while (true) {
        input>>codigo;
        if (input.eof())break;
        input.get();
        buffer_codigos[n_datos] = codigo;
        buffer_nombres[n_datos] = leer_cadena(input, '\n');
        n_datos++;
    }
}

void pasar_datos(int*& codigos, char**&nombres, int* buffer_codigos, char** buffer_nombres, int n_datos) {
    codigos = new int[n_datos] {
    };
    nombres = new char*[n_datos] {
    };

    for (int i = 0; i < n_datos; i++) {
        codigos[i] = buffer_codigos[i];
        nombres[i] = buffer_nombres[i];
    }
}

void cargar_alumnos(int*& codigos, char**&nombres, const char* nombre_archivo) {
    ifstream input;
    AperturaDeUnArchivoDeTextosParaLeer(input, nombre_archivo);
    int buffer_codigos[MAX_ALUMNOS]{}, n_datos = 0;
    char* buffer_nombres[MAX_ALUMNOS]{};
    leer_datos(input, buffer_codigos, buffer_nombres, n_datos);
    pasar_datos(codigos, nombres, buffer_codigos, buffer_nombres, ++n_datos);
}

// =============================================================================
// 4. Lectura y Almacenamiento de Alumnos (memoria dinámica por incrementos)
// =============================================================================

void cargar_alumnos_incrementos(int*&codigos, char**&nombres, const char*nombre_archivo) {
    int capacidad = 0, n_alumnos = 0;
    int codigo = 0;
    char *nombre = nullptr;
    ifstream input(nombre_archivo, ios::in);
    if (not input.is_open()) {
        cout << "El archivo " << nombre_archivo << "no se abrio" << endl;
        exit(1);
    }
    codigos = nullptr;
    nombres = nullptr;
    while (true) {
        input>>codigo;
        if (input.eof())break;
        input.get();
        nombre = leer_cadena(input, '\n');
        if (capacidad == n_alumnos)
            reservar_memoria_incrementos(codigos, nombres, n_alumnos, capacidad);
        codigos[n_alumnos - 1] = codigo;
        nombres[n_alumnos - 1] = nombre;
        n_alumnos++;
    }
}

void reservar_memoria_incrementos(int*&codigos, char**&nombres, int &n_alumnos, int &capacidad) {
    int *aux_codigos;
    char **aux_nombres;
    capacidad += INCREMENTO;
    if (codigos == nullptr) {
        codigos = new int[capacidad] {
        };
        nombres = new char*[capacidad] {
        };
        n_alumnos = 1;
    } else {
        aux_codigos = new int [capacidad] {
        };
        aux_nombres = new char*[capacidad] {
        };
        for (int i = 0; i < n_alumnos; i++) {
            aux_codigos[i] = codigos[i];
            aux_nombres[i] = nombres[i];
        }
        delete codigos;
        delete nombres;
        codigos = aux_codigos;
        nombres = aux_nombres;
    }
}

// =============================================================================
// 5. Lectura y Almacenamiento de Cursos (memoria fija)
// =============================================================================

void agregar_curso(ifstream &input, char**cursos_alumno, int &n) {
    char *codigo = leer_cadena(input, '\n');
    cursos_alumno[n] = codigo;
    n++;
}

void leer_cursos(ifstream& input, int* codigos, char***cursos, int* n_cursos_alumno) {
    int codigo, pos;
    while (true) {
        input>>codigo;
        if (input.eof()) break;
        input.get();
        pos = buscar(codigos, codigo);
        if (pos != -1)
            agregar_curso(input, cursos[pos], n_cursos_alumno[pos]);
    }
}

void recortar(char** &cursos_alumnos, int n) {
    char** cursos_alumnos_temporal;
    if (n != 0) {
        cursos_alumnos_temporal = new char*[n + 1] {
        };
        for (int i = 0; i < n; i++)
            cursos_alumnos_temporal[i] = cursos_alumnos[i];
        delete cursos_alumnos;
        cursos_alumnos = cursos_alumnos_temporal;
    } else {
        delete cursos_alumnos;
        cursos_alumnos = nullptr;
    }
}

void recortar_cursos(int n_alumnos, char***&cursos, int* n_cursos_alumno) {
    for (int i = 0; i < n_alumnos; i++)
        recortar(cursos[i], n_cursos_alumno[i]);
}

void cargar_cursos(int* codigos, char***&cursos, const char*nombre_archivo) {
    ifstream input;
    AperturaDeUnArchivoDeTextosParaLeer(input, nombre_archivo);
    int n_alumnos = 0;
    while (codigos[n_alumnos])n_alumnos++;
    int n_cursos_alumno[n_alumnos]{};
    cursos = new char**[n_alumnos] {
    };
    for (int i = 0; i < n_alumnos; i++)
        cursos[i] = new char*[MAX_CURSOS_ALUMNO];
    leer_cursos(input, codigos, cursos, n_cursos_alumno);
    recortar_cursos(n_alumnos, cursos, n_cursos_alumno);
}

// =============================================================================
// 6. Lectura y Almacenamiento de Cursos (memoria dinámica por incrementos)
// =============================================================================

void reservar_memoria_incrementos(char**&cursos, int&cantidad, int&capacidad) {
    char** aux_cursos;
    capacidad += INCREMENTO;
    if (cursos == nullptr) {
        cursos = new char*[capacidad] {
        };
        cantidad = 1;
    } else {
        aux_cursos = new char*[capacidad] {
        };
        for (int i = 0; i < cantidad; i++)
            aux_cursos[i] = cursos[i];
        delete cursos;
        cursos = aux_cursos;
    }
}

void colocar_curso(ifstream &input, char**&cursos_alumnos, int &cantidad, int &capacidad) {
    char* curso;
    curso = leer_cadena(input, '\n');
    if (cantidad == capacidad)
        reservar_memoria_incrementos(cursos_alumnos, cantidad, capacidad);
    cursos_alumnos[cantidad - 1] = curso;
    cantidad++;
}

void cargar_cursos_incrementos(int* codigos, char*** &cursos, const char* nombre_archivo) {
    ifstream input(nombre_archivo, ios::in);
    if (not input.is_open()) {
        cout << "El archivo " << nombre_archivo << "no se abrio" << endl;
        exit(1);
    }
    int cantidad_datos = 0, codigo, indice;
    int cantidades[50]{}, capacidades[50]{};
    while (codigos[cantidad_datos])cantidad_datos++;
    cursos = new char**[cantidad_datos + 1] {
    };
    while (true) {
        input>>codigo;
        if (input.eof())break;
        input.get();
        indice = buscar(codigos, codigo);
        if (indice != -1) {
            colocar_curso(input, cursos[indice], cantidades[indice], capacidades[indice]);
        } else
            while (input.get() != '\n');
    }
}
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "funciones.hpp"

void cargar_alumnos(void *&al) {
    void **alumno = nullptr, *reg;
    int numDat = 0, cap = 0;
    ifstream arch("Alumnos.csv", ios::in);
    if (not arch.is_open()) {
        cout << "Error, no se pucde abrir el archivo Alumnos.csv" << endl;
        exit(1);
    }
    while (true) {
        reg = leer_registro(arch);
        if (arch.eof())break;
        if (numDat == cap) incrementar_espacios(alumno, numDat, cap);
        alumno[numDat] = nullptr;
        alumno[numDat - 1] = reg;
        numDat++;
    }
    al = alumno;
}

void *leer_registro(ifstream &arch) {
    void **registro;
    int *codigo, cod;
    char *nombre;
    arch>>cod;
    if (arch.eof())return nullptr;
    arch.get(); //Leemos la coma
    nombre = leer_cadena(arch);
    codigo = new int;
    *codigo = cod;
    registro = new void*[2];
//    cout<<*codigo<<endl;
//    cout<<nombre<<endl;
    registro[0] = codigo;
    registro[1] = nombre;
    return registro;
}

void incrementar_espacios(void **&alumno, int &numDat, int &cap) {
    void**aux;
    cap += INCREMENTO;
    if (alumno == nullptr) {
        alumno = new void*[cap];
        alumno[0] = nullptr;
        numDat = 1;
    } else {
        aux = new void *[cap];
        for (int i = 0; i < numDat; i++)
            aux[i] = alumno[i];
        delete alumno;
        alumno = aux;
    }
}

void reporte_alumnos(void *alu) {
    void **alumno = (void **) alu;
    for (int i = 0; alumno[i]; i++)
        imprimir_alumno(alumno[i]);
}

void imprimir_alumno(void *alu) {
    void **alumno = (void**) alu;
    int *codigo = (int*) alumno[0];
    char *nombre = (char*) alumno[1];
    cout << right << setw(10) << *codigo << " " << left << setw(20) << nombre << endl;
}

char *leer_cadena(ifstream &arch) {
    char buff[200], *nomb;
    arch.getline(buff, 200,'\n');
    nomb = new char[strlen(buff) + 1];
    strcpy(nomb, buff);
    return nomb;
}
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "funciones.hpp"

void cargarAlumnos(int *&codigo, char **&nombre, char ***&cursos) {
    int numDat = 0, cap = 0, cod;
    char *nomb, **cur;
    ifstream arch("Alumnos-Cursos.csv", ios::in);
    if (not arch.is_open()) {
        cout << "ERROR, no se pudo abrir el archivo " << "Alumnos-Cursos.csv" << endl;
        exit(1);
    }

    codigo = nullptr;
    nombre = nullptr;
    cursos = nullptr;
    while (true) {
        arch>>cod;
        if (arch.eof())break;
        arch.get();
        nomb = leeCadena(arch);
        cur = leeCursos(arch);
        if (numDat == cap)
            aumentarEspacios(codigo, nombre, cursos, numDat, cap);
        codigo[numDat] = 0;
        codigo[numDat - 1] = cod;
        nombre[numDat] = nullptr;
        nombre[numDat - 1] = nomb;
        cursos[numDat] = nullptr;
        cursos[numDat - 1] = cur;
        numDat++;
    }
}

char *leeCadena(ifstream &arch) {
    char buffCad[60], *nombre;
    arch.getline(buffCad, 60, ',');
    nombre = new char[strlen(buffCad) + 1];
    strcpy(nombre, buffCad);
    return nombre;
}

char **leeCursos(ifstream &arch) {
    char **curso = nullptr, *cur = nullptr;
    int nd = 0, cap = 0;

    while (true) {
        cur = leerCad(arch);
        if (nd == cap)
            aumentarEspacios(curso, nd, cap);
        curso[nd] = nullptr;
        curso[nd - 1] = cur;
        nd++;
        if (arch.get() == '\n')break;
    }
    return curso;
}

void aumentarEspacios(int *&codigo, char **&nombre, char ***&cursos, int &numDat,
        int &cap) {
    int *auxC;
    char **auxN, ***auxCur;
    cap += INCREMENTO;
    if (codigo == nullptr) {
        codigo = new int[cap];
        nombre = new char*[cap];
        cursos = new char**[cap];
        codigo[0] = 0;
        nombre[0] = nullptr;
        cursos[0] = nullptr;
        numDat = 1;
    } else {
        auxC = new int[cap];
        auxN = new char*[cap];
        auxCur = new char**[cap];
        for (int i = 0; i < numDat; i++) {
            auxC[i] = codigo[i];
            auxN[i] = nombre[i];
            auxCur[i] = cursos[i];
        }
        delete codigo;
        delete nombre;
        delete cursos;

        codigo = auxC;
        nombre = auxN;
        cursos = auxCur;
    }
}

char *leerCad(ifstream &arch) {
    char *cad = new char[7];
    arch.get(cad, 7);
    return cad;
}

void aumentarEspacios(char **&curso, int &nd, int &cap) {
    char **auxC;
    cap += INCREMENTO;
    if (curso == nullptr) {
        curso = new char*[cap];
        curso[0] = nullptr;
        nd = 1;
    } else {
        auxC = new char*[cap];
        for (int i = 0; i < nd; i++)
            auxC[i] = curso[i];
        delete curso;
        curso = auxC;
    }
}
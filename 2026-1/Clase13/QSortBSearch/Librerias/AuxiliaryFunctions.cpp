//
// Created by erasmo on 5/5/26.
//

#include "AuxiliaryFunctions.hpp"

void imprimir_alumno(const Alumno &alumno) {
    cout << left << setw(10) << alumno.codigo
            << setw(20) << alumno.nombre
            << right << setw(8) << alumno.nota << endl;
}

void imprimir_reporte(void **arr_alumnos, int n) {
    cout << left << setw(10) << "CODIGO"
            << setw(20) << "NOMBRE"
            << right << setw(8) << "NOTA" << endl;

    cout << "--------------------------------------" << endl;

    for (int i = 0; i < n; i++) {
        Alumno *alumno = (Alumno *) arr_alumnos[i];
        imprimir_alumno(*alumno);
    }
}

int comparar_por_codigo(const void *a, const void *b) {
    void *ptrA = *(void **) a;
    void *ptrB = *(void **) b;

    Alumno *alumnoA = (Alumno *) ptrA;
    Alumno *alumnoB = (Alumno *) ptrB;

    return alumnoA->codigo - alumnoB->codigo;
}

int comparar_por_nota_desc(const void *a, const void *b) {
    Alumno *alumnoA = (Alumno *) (*(void **) a);
    Alumno *alumnoB = (Alumno *) (*(void **) b);

    if (alumnoA->nota < alumnoB->nota) return 1;
    if (alumnoA->nota > alumnoB->nota) return -1;
    return 0;
}

int comparar_por_nombre_alfambeticamente(const void *a, const void *b) {
    Alumno *alumnoA = (Alumno *) (*(void **) a);
    Alumno *alumnoB = (Alumno *) (*(void **) b);
    //cout<<"Accediendo a los nombres"<<endl;
    // cout<<alumnoA->nombre<<endl;
    // cout<<alumnoB->nombre<<endl;
    return strcmp(alumnoA->nombre, alumnoB->nombre)>0;
}

int comparar_codigo_bsearch(const void *key, const void *element) {
    int codigo_buscado = *(int *) key;

    Alumno *alumno = (Alumno *) (*(void **) element);

    return codigo_buscado - alumno->codigo;
}

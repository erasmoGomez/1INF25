//
// Created by erasmo on 5/5/26.
//

#ifndef QSORT_AUXILIARYFUNCTIONS_HPP
#define QSORT_AUXILIARYFUNCTIONS_HPP
#include "Structs.hpp"

void imprimir_alumno(const Alumno &alumno);

void imprimir_reporte(void **arr_alumnos, int n);

int comparar_por_codigo(const void *a, const void *b);

int comparar_por_nota_desc(const void *a, const void *b);

int comparar_por_nombre_alfambeticamente(const void *a, const void *b);

int comparar_codigo_bsearch(const void *key, const void *element);

#endif //QSORT_AUXILIARYFUNCTIONS_HPP

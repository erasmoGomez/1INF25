//
// Created by Erasmo on 16/09/25.
//

#ifndef PUNTEROSVOIDALUMNOSCURSOS_FUNCIONES_GENERICAS_HPP
#define PUNTEROSVOIDALUMNOSCURSOS_FUNCIONES_GENERICAS_HPP
#include "Utils.hpp"
void cargar_alumnos(void*&, const char*);
void cargar_notas(void*, const char*);
void calcular_promedio(void*);
void probar_carga(void*, const char*);
void ordenar(void*);
int obtener_cantidad(void *alumnos);
void quick_sort_generico(void *alumnos, int izq, int der, int(*cmp)(const void *, const void *));
int comparar_orden_generico(const void *al1, const void *al2);
#endif //PUNTEROSVOIDALUMNOSCURSOS_FUNCIONES_GENERICAS_HPP

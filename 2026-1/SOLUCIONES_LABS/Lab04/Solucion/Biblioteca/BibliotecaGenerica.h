//
// Created by Daniel Sanchez on 8/05/26.
//

#ifndef SOLUCION_LIST_H
#define SOLUCION_LIST_H

#include <fstream>

enum LISTA {
    INICIO = 0,
    LONGITUD,
    LISTA_COUNT,
};

enum NODO {
    DATA = 0,
    SIG,
    NODO_COUNT,
};

void procesaArreglo(void **array, void * (*read)(std::ifstream &),
                    const char *file_name);

void creaLista(void **array, void *&list,
               int (*cmp)(const void *a, const void *b));

void fusionaListas(void *list1, void *list2,
                   int (*verify)(const void *a, const void *b));

void imprimeLista(void *list, void (*print)(std::ostream &, void *),
                  std::ostream &file);

void imprimeLista(void *list, void (*print)(std::ostream &, void *),
                  const char *file_name);

#endif //SOLUCION_LIST_H

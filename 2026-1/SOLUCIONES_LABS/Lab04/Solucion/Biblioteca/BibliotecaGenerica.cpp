//
// Created by Daniel Sanchez on 8/05/26.
//

#include "BibliotecaGenerica.h"

#include <fstream>
#include <iostream>

void procesaArreglo(void **array, void * (*read)(std::ifstream &),
                    const char *file_name) {
    std::ifstream file;
    file.open(file_name, std::ios::in);
    if (not file.is_open()) {
        std::cerr << "Error al abrir el archivo: " << file_name << std::endl;
        exit(1);
    }
    int i = 0;
    while (true) {
        void *data = read(file);
        if (data == nullptr) break;
        array[i] = data;
        i += 1;
    }
}

int count_elements(void **array) {
    int i = 0;
    for (; array[i] != nullptr; i++) {
    }
    return i;
}

void generaLista(void *&list) {
    void **list_arr = new void *[LISTA_COUNT]{};
    int *size_ptr = new int(0);
    list_arr[INICIO] = nullptr;
    list_arr[LONGITUD] = size_ptr;
    list = list_arr;
}

void insertaLista(void *list, void *data) {
    void **node = new void *[NODO_COUNT]{};
    node[DATA] = data;
    node[SIG] = nullptr;

    void **list_arr = (void **) list;
    if (list_arr[INICIO] == nullptr) {
        list_arr[INICIO] = node;
    } else {
        node[SIG] = list_arr[INICIO];
        list_arr[INICIO] = node;
    }
    int *longitud = (int *) list_arr[LONGITUD];
    *longitud += 1;
}

void creaLista(void **array, void *&list,
               int (*cmp)(const void *a, const void *b)) {
    int n = count_elements(array);
    qsort(array, n, sizeof(void *), cmp);
    generaLista(list);
    for (int i = n - 1; i >= 0; i--) {
        insertaLista(list, array[i]);
    }
}

void fusionaListas(void *list1, void *list2,
                   int (*verify)(const void *a, const void *b)) {
    void **list1_arr = (void **) list1;
    void **list2_arr = (void **) list2;
    void **node1 = (void **) list1_arr[INICIO];
    void **node2 = (void **) list2_arr[INICIO];
    void **ant1 = nullptr;

    while (node1 != nullptr && node2 != nullptr) {
        if (verify(node1[DATA], node2[DATA]) > 0) {
            // Inserta node2 antes que node1
            if (ant1 == nullptr) {
                list1_arr[INICIO] = node2;
            } else {
                ant1[SIG] = node2;
            }
            void **temp = (void **) node2[SIG];
            node2[SIG] = node1;
            ant1 = node2;
            node2 = temp;
        } else {
            // Avanza node1
            ant1 = node1;
            node1 = (void **) node1[SIG];
        }
    }

    // Agrega nodos que faltan de list2 (si quedan)
    if (node2 != nullptr) {
        if (ant1 == nullptr) {
            list1_arr[INICIO] = node2;
        } else {
            ant1[SIG] = node2;
        }
    }
}

void imprimeLista(void *list, void (*print)(std::ostream &, void *),
                  std::ostream &file) {
    void **list_arr = (void **) list;
    void **nodo = (void **) list_arr[INICIO];
    for (int i = 0; nodo != nullptr; i++) {
        print(file, nodo[DATA]);
        nodo = (void **) nodo[SIG];
    }
}

void imprimeLista(void *list, void (*print)(std::ostream &, void *),
                  const char *file_name) {
    std::ofstream file;
    file.open(file_name, std::ios::out);
    if (not file.is_open()) {
        std::cerr << "Error al abrir el archivo: " << file_name << std::endl;
        exit(1);
    }
    imprimeLista(list, print, file);
}

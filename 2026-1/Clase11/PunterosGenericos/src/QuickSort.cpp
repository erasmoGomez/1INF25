//
// Created by erasmo on 4/28/26.
//

#include "QuickSort.hpp"

/*
 * Quick Sort ordena el arreglo dividiendo el problema en sub arreglos.
 *
 * En cada llamada:
 * 1. Se elige un pivote.
 * 2. Se mueve el pivote al inicio del sub arreglo.
 * 3. Se recorren los elementos y se mandan los menores a la izquierda.
 * 4. Se coloca el pivote en su posición final.
 * 5. Se aplica recursión sobre:
 *      - el sub arreglo izquierdo
 *      - el sub arreglo derecho
 *
 * Importante:
 * Después de la partición, el pivote ya queda ordenado definitivamente.
 *
 * Level no forma parte del algoritmo Quick Sort.
 * Solo se usa para identificar visualmente las llamadas recursivas.
 */
#include "QuickSort.hpp"

#include <iostream>

void my_swap(void * &x, void * &y) {
    void *temp = x;
    x = y;
    y = temp;
}

bool compara_void_int(void *a, void *b) {
    void **registro_a = (void **) a;
    void **registro_b = (void **) b;
    int *ptr_a = (int *) registro_a[CODIGO];
    int *ptr_b = (int *) registro_b[CODIGO];
    // cout << *ptr_a << " " << *ptr_b << endl;
    // return strcmp(ptr_a, ptr_b) < 0
    return *ptr_a < *ptr_b;
}

void quick_sort(void *arreglo, int left, int right) {
    void **arreglo_recorrido = (void **) arreglo;
    // Caso base:
    // Si el segmento tiene 0 o 1 elementos, ya está ordenado.
    if (left >= right) {
        return;
    }

    const int pivot = (left + right) / 2;

    /*
     * Elegimos el pivote del medio del segmento actual.
     * Luego lo moveremos al inicio para que arreglo[left]
     * sea tratado como pivote durante la partición.
     */
    my_swap(arreglo_recorrido[left], arreglo_recorrido[pivot]);

    /*
     * Limit marca la frontera de la zona de elementos menores al pivote.
     *
     * Invariante durante el for:
     * - arreglo[left] contiene el pivote.
     * - los elementos entre left + 1 y limit son menores que el pivote.
     * - los elementos entre limit + 1 e i - 1 son mayores o iguales al pivote.
     */
    int limit = left;

    for (int i = left + 1; i <= right; i++)
        if (compara_void_int(arreglo_recorrido[i], arreglo_recorrido[left]))
            my_swap(arreglo_recorrido[++limit], arreglo_recorrido[i]);

    /*
     * Colocamos el pivote en su posición final.
     * Todo lo que queda a su izquierda es menor.
     * Todo lo que queda a su derecha es mayor o igual.
     */
    my_swap(arreglo_recorrido[left], arreglo_recorrido[limit]);
    /*
     * Ordenamos recursivamente las dos zonas restantes.
     * El pivote ya no se toca.
     */

    quick_sort(arreglo_recorrido, left, limit - 1);
    quick_sort(arreglo_recorrido, limit + 1, right);
}

//
// Created by erasmo on 4/23/26.
//

#include "funciones.hpp"

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

void print_indent(const int level) {
    for (int i = 0; i < level; i++)
        cout << "  ";
}

void print_separator(const int level) {
    print_indent(level);
    cout << setfill('=') << setw(60-level) << "" << setfill(' ') << endl;
}

void print_array_with_indent(const int *arreglo, const int left, const int right, const int level) {
    print_indent(level);
    print_array(arreglo, left, right + 1);
}

void print_base_case(const int left, const int right, const int level) {
    print_indent(level);
    cout << "CASO BASE | Nivel " << level
         << " | Rango [" << left << ", " << right << "]" << endl;
}

void print_start_call(const int *arreglo, const int left, const int right,
                      const int pivot, const int level) {
    print_separator(level);

    print_indent(level);
    cout << "Nivel de recursion: " << level << endl;

    print_indent(level);
    cout << "Rango actual: [" << left << ", " << right << "]" << endl;

    print_indent(level);
    cout << "Pivot elegido: " << arreglo[pivot] << endl;

    print_indent(level);
    cout << "ANTES DE MOVER EL PIVOTE AL INICIO" << endl;

    print_array_with_indent(arreglo, left, right, level);
}

void print_after_pivot_swap(const int *arreglo, const int left, const int right,
                            const int level) {
    print_indent(level);
    cout << "DESPUES DE MOVER EL PIVOTE AL INICIO" << endl;

    print_array_with_indent(arreglo, left, right, level);
}

void print_after_partition(const int *arreglo, const int left, const int right,
                           const int level) {
    print_indent(level);
    cout << "DESPUES DE AGRUPAR LOS MENORES QUE EL PIVOTE" << endl;

    print_array_with_indent(arreglo, left, right, level);
}

void print_after_pivot_final_position(const int *arreglo, const int left, const int right,
                                      const int limit, const int level) {
    print_indent(level);
    cout << "DESPUES DE COLOCAR EL PIVOTE EN SU POSICION FINAL" << endl;

    print_array_with_indent(arreglo, left, right, level);

    print_indent(level);
    cout << "Pivote fijo en la posicion " << limit
         << ": " << arreglo[limit] << endl;

    print_separator(level);
}

void print_recursive_calls(const int left, const int right,
                           const int limit, const int level) {
    print_indent(level);
    cout << "LLAMADAS RECURSIVAS DESDE NIVEL " << level << endl;

    print_indent(level);
    cout << "Izquierda: quick_sort(arreglo, "
         << left << ", " << limit - 1 << ", " << level + 1 << ")" << endl;

    print_indent(level);
    cout << "Derecha: quick_sort(arreglo, "
         << limit + 1 << ", " << right << ", " << level + 1 << ")" << endl;
}

void my_swap(int &x, int &y) {
    const int temp = x;
    x = y;
    y = temp;
}

void print_array(const int *arreglo, const int from, const int n) {
    for (int i = from; i < n; i++) {
        cout << arreglo[i] << " ";
    }
    cout << endl;
}

void quick_sort(int *arreglo, const int left, const int right, const int level) {
    // Caso base:
    // Si el segmento tiene 0 o 1 elementos, ya está ordenado.
    if (left >= right) {
        print_base_case(left, right, level);
        return;
    }

    const int pivot = (left + right) / 2;

    /*
     * Elegimos el pivote del medio del segmento actual.
     * Luego lo moveremos al inicio para que arreglo[left]
     * sea tratado como pivote durante la partición.
     */
    print_start_call(arreglo, left, right, pivot, level);

    my_swap(arreglo[left], arreglo[pivot]);

    print_after_pivot_swap(arreglo, left, right, level);

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
        if (arreglo[i] < arreglo[left])
            my_swap(arreglo[++limit], arreglo[i]);

    print_after_partition(arreglo, left, right, level);

    /*
     * Colocamos el pivote en su posición final.
     * Todo lo que queda a su izquierda es menor.
     * Todo lo que queda a su derecha es mayor o igual.
     */
    my_swap(arreglo[left], arreglo[limit]);

    print_after_pivot_final_position(arreglo, left, right, limit, level);

    /*
     * Ordenamos recursivamente las dos zonas restantes.
     * El pivote ya no se toca.
     */
    print_recursive_calls(left, right, limit, level);

    quick_sort(arreglo, left, limit - 1, level + 1);
    quick_sort(arreglo, limit + 1, right, level + 1);
}

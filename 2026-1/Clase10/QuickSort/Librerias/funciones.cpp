//
// Created by erasmo on 4/23/26.
//

#include "funciones.hpp"

/*                          LLAMADA 0
 *                    /                    \
 *                   /                      \
 *       Llamada 0.1                         Llamada -0.1
 *      /           \                       /            \
 * Llamada 0,2       Llamada 0     Llamada 0              Llamada - 0.2
 */
void quick_sort(int *arreglo, int left, int right, double n_call) {
    int pivot = (left + right) / 2;
    int limit;
    cout << setfill('=') << setw(40) << "" << setfill(' ') << endl;
    cout << "Pivot: " << setw(5) << arreglo[pivot] << endl;
    if (left >= right) {
        cout << "SALIMOS DE LA RECURSIVA: " << n_call << endl;
        return;
    }
    cout << "ANTES DEL SWAP PIVOT" << endl;
    print_array(arreglo, left, right + 1);
    my_swap(arreglo[left], arreglo[pivot]);
    cout << "DESPUES DEL SWAP PIVOT" << endl;
    print_array(arreglo, left, right + 1);
    limit = left;
    for (int i = left + 1; i <= right; i++)
        if (arreglo[i] < arreglo[left])
            my_swap(arreglo[++limit], arreglo[i]);
    cout << "DESPUES DE UBICAR MENORES AL PIVOT A LA IZQ Y MAYORES AL PIVOT A LA DERECHA" << endl;
    print_array(arreglo, left, right + 1);
    my_swap(arreglo[left], arreglo[limit]);
    cout << "DESPUES DEL SWAP" << endl;
    cout << setw(10) << "Llamada: " << n_call << endl;
    print_array(arreglo, left, right + 1);
    cout << setfill('=') << setw(40) << "" << setfill(' ') << endl;
    cout << "LLAMADAS RECURSIVAS! DESDE N_CALL: " << n_call << endl;;
    quick_sort(arreglo, left, limit - 1, n_call + 0.1);
    quick_sort(arreglo, limit + 1, right, n_call - 0.1);
}

void my_swap(int &x, int &y) {
    int temp;
    temp = x;
    x = y;
    y = temp;
}

void print_array(int *arreglo, int from, int n) {
    for (int i = from; i < n; i++) {
        cout << arreglo[i] << " ";
    }
    cout << endl;
}

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
    // cout << setfill('=') << setw(40) << "" << setfill(' ') << endl;
    // cout << "Pivot: " << setw(5) << arreglo[pivot] << endl;
    // CASO BASE : Cuando Solo tengo un elemento en el arreglo.
    // [112] [22] [3] [5] [56] [32] [12]
    // va a parar si yo le mando el arreglo completo pero con indice left = 0 e indice right = 0
    // El > se coloca cuando el valor a encontrar tampoco esta en el arreglo. left 3 right 2
    if (left >= right) {
        cout << "SALIMOS DE LA RECURSIVA: " << n_call << endl;
        return;
    }
    cout << "ANTES DEL SWAP PIVOT" << endl;
    print_array(arreglo, left, right + 1);
    my_swap(arreglo[left], arreglo[pivot]);
    cout << "DESPUES DEL SWAP PIVOT" << endl;
    print_array(arreglo, left, right + 1);
    // 2 4 14 17 10 5 21 11 1
    // 10 2, 10 4, 10 14, 10 17, [10 10], 10 5, 10 21, 10 11, 10 1 esto no es eficiente
    // 10 4 14 17 2 5 21 11 1
    // 10 10 4, 10 14, 10 17, 10 2, 10 5, 10 21, 10 11, 10 1
    limit = left; // Este limite representa que a la izq van a ir los valores menores que el pivote y a su derecha los mayores
    for (int i = left + 1; i <= right; i++)
        if (arreglo[i] < arreglo[left])
            my_swap(arreglo[++limit], arreglo[i]); // Esto va a ocurrir cuando hay un numero menor que el pivote y se ubica a la izq del limite
    cout << "DESPUES DE UBICAR MENORES AL PIVOT A LA IZQ Y MAYORES AL PIVOT A LA DERECHA" << endl;
    print_array(arreglo, left, right + 1);
    my_swap(arreglo[left], arreglo[limit]); // esto coloca al pivote en la posicion correcta
    cout << "DESPUES DEL SWAP" << endl;
    cout << setw(10) << "Llamada: " << n_call << endl;
    print_array(arreglo, left, right + 1);
    cout << setfill('=') << setw(40) << "" << setfill(' ') << endl;
    cout << "LLAMADAS RECURSIVAS! DESDE N_CALL: " << n_call << endl;
    quick_sort(arreglo, left, limit - 1, n_call + 0.1); // llamada a la izq
    quick_sort(arreglo, limit + 1, right, n_call - 0.1); // llamada a la der
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

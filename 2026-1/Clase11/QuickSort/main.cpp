#include "Librerias/funciones.hpp"

int main() {
    int arreglo[9] = {2, 4, 14, 17, 10, 5, 21, 11, 1};
    int n = 9;

    /*
     * Ordenamos todo el arreglo usando Quick Sort.
     *
     * Parámetros:
     * - arreglo: arreglo que queremos ordenar.
     * - 0: índice inicial del segmento.
     * - n - 1: índice final del segmento.
     * - 0: valor usado solo para visualizar las llamadas recursivas.
     *
     * Importante:
     * El último parámetro no pertenece al algoritmo Quick Sort.
     * Solo ayuda a imprimir y distinguir las llamadas durante la explicación.
     */

    quick_sort(arreglo, 0, n - 1, 0);
    cout << "ARREGLO FINAL ORDENADO:" << endl;
    print_array(arreglo, 0, n);

    return 0;
}
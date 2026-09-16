#include "Librerias/funciones.hpp"

int main() {
    int arreglo[9] = {2, 4, 14, 17, 10, 5, 21, 11, 1};
    int n = 9;
    // print_array(arreglo, 0,  n);
    quick_sort(arreglo, 0, n - 1, 0.0); // El ultimo parametro solo es para debug y que peudan viualizar las llamadas.
    print_array(arreglo, 0, n);
    return 0;
}
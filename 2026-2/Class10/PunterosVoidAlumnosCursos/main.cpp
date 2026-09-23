#include "srx/funciones_genericas.hpp"

int main() {
    void *alumnos;
    cargar_alumnos(alumnos, "Data/Alumnos.csv");
    cargar_notas(alumnos, "Data/CursosNotas.csv");
    calcular_promedio(alumnos);
    probar_carga(alumnos, "Reports/reporte1_promedio.txt");

    int cantidad = 0;
    cantidad = obtener_cantidad(alumnos);

    // Ordenar Básico
    // ordenar(alumnos);
    // probar_carga(alumnos, "Reports/reporte_ordenado.txt");


    // QuickSort Genérico
    // quick_sort_generico(alumnos, 0, cantidad - 1, comparar_orden_generico);
    // probar_carga(alumnos, "Reports/reporte_ordenado_generio.txt");

    // QSORT
    qsort(alumnos, cantidad, sizeof(void*), comparar_orden_generico_qsort);
    probar_carga(alumnos, "Reports/reporte_ordenado_generio_qsort.txt");


    return 0;
}

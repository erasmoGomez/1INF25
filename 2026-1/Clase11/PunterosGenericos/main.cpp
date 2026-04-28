#include <iostream>

#include "src/Alumnos.hpp"

int main() {
    void *alumnos;
    int num_alumnos = 0;
    cargar_alumnos(alumnos, "Data/personal.csv", num_alumnos);
    prueba_carga_alumnos(alumnos, "Reports/reporte_alumnos.csv");
    quick_sort(alumnos, 0, num_alumnos - 1);
    prueba_carga_alumnos(alumnos, "Reports/reporte_alumnos_ordenado.csv");

    return 0;
}

#include "srx/funciones_genericas.hpp"

int main() {
    void *alumnos;
    cargar_alumnos(alumnos, "Data/Alumnos.csv");
    cargar_notas(alumnos, "Data/CursosNotas.csv");
    // calcular_promedio(alumnos);
    probar_carga(alumnos, "Reports/reporte1.txt");
    // ordenar(alumnos);
    // probar_carga(alumnos, "reporte_ordenado.txt");
    return 0;
}

#include "Bibliotecas/funciones_genericas.hpp"

int main() {
    void *alumnos;
    cargar_alumnos(alumnos, "Data/Alumnos.csv");
    cargar_notas(alumnos, "Data/CursosNotas.csv");
    void **recorrido = static_cast<void **>(alumnos);
    int n_elements = 0;
    for (n_elements = 0; recorrido[n_elements]; n_elements++) {
    }
    qsort(alumnos,
          n_elements,
          sizeof(void *),
          compara_alumnos);
    probar_carga(alumnos, "Reports/ReporteAlumnos.txt");
    return 0;
}

#include "src/Alumnos.hpp"

int main() {
    void *alumnos;
    cargar_alumnos(alumnos, "Data/Alumnos.csv");
    prueba_carga_alumnos(alumnos, "Reports/reporte_alumnos.csv");
    return 0;
}

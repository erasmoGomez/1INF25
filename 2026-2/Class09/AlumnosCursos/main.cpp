#include "Bibliotecas/funciones_genericas.hpp"

int main() {
    void* alumnos;
    cargar_alumnos(alumnos, "Data/Alumnos.csv");
    cargar_notas(alumnos, "Data/CursosNotas.csv");

    return 0;
}

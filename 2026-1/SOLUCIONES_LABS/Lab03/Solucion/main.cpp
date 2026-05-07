#include <iostream>
#include "Biblioteca/Hospital.h"

int main() {
    void *pacientes;
    cargarPacientes("Data/pacientes.csv", pacientes);
    generarReporte("Reports/reporte0.txt", pacientes);
    cargarVisitas("Data/visitas.csv", pacientes);
    generarReporte("Reports/reporte1.txt", pacientes);
    return 0;
}
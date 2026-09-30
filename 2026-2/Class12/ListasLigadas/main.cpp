#include "src/ListaEmpleados.hpp"

int main() {
    void *lista_empleados;
    crear_lista("Data/personal.csv",
                lista_empleados,
                lee_empleado,
                compara_empleado_nombre);
    imprimir_lista("Reports/reporte_personal.txt",
                   lista_empleados,
                   imprime_empleado);
    crear_lista_2("Data/personal.csv",
                lista_empleados,
                lee_empleado);
    imprimir_lista("Reports/reporte_personal_inicio.txt",
                   lista_empleados,
                   imprime_empleado);
    return 0;
}

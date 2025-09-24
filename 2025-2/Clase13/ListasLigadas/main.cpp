#include "src/ListaGenerica.hpp"
#include "src/ListaEmpleados.hpp"

int main() {
    void* lista_empleados;
    crear_lista("Data/personal.csv", lista_empleados, lee_empleado, compara_empleado_nombre);
    imprimir_lista(lista_empleados, imprime_empleado);
    return 0;
}


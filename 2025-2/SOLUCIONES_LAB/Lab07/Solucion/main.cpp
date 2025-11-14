#include <iostream>

#include "GestorStreamers.h"

int main() {
    GestorStreamers gestor;
    gestor.cargar_datos_streamers("streamers.csv");
    gestor.actualizar_datos_metricas("metricas.csv");
    gestor.generar_reportes();
    return 0;
}

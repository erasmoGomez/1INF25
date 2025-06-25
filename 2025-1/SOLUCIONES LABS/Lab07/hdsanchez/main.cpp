#include "MinisterioDeTransportes.hpp"

int main(int argc, char *argv[]) {
  class MinisterioDeTransportes minis;
  minis.leer_zonas("./Datos/zonas.txt");
  minis.cargar_drones("./Datos");
  minis.procesar_todos_los_eventos("./Datos");
  minis.imprimir("Reporte.txt");
  return 0;
}
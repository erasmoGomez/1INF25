#include "MinisterioDeTransporte.hpp"

int main(int argc, char *argv[]) {
  class MinisterioDeTransporte ministerio;
  ministerio < "TablaDeInfracciones.csv";
  ministerio <= "EmpresasRegistradas.csv";
  ministerio <<= "InfraccionesCometidas.csv";
  ministerio >> "ReporteParaElMinisterio.txt";
  return 0;
}
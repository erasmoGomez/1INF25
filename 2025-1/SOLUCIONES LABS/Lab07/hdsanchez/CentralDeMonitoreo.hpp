#pragma once

#include "Flota.hpp"

#include <fstream>

class CentralDeMonitoreo {
public:
  CentralDeMonitoreo() {
    cantidad_multas_registradas = 0;
    total_multas_acumuladas = 0.0;
  }

  ~CentralDeMonitoreo() {}

  void cargar_drones(std::ifstream &arch) {
    while (true) {
      char tipo[20];
      arch.getline(tipo, 20, ',');
      if (arch.eof())
        break;
      flota.cargar_drone(arch, tipo);
    }
  }

  void cargar_infracciones(std::ifstream &arch) {
    flota.actualizarDronesInfracciones(arch);
    cantidad_multas_registradas = flota.cantidad_multas_registradas();
    total_multas_acumuladas = flota.total_multas_acumuladas();
  }

  void imprimir(std::ofstream &arch) const {
    arch << "CANTIDAD DE MULTAS REGISTRADAS: " << cantidad_multas_registradas
         << std::endl;
    arch << "TOTAL DE MULTAS ACUMULADAS: " << total_multas_acumuladas
         << std::endl;
    flota.imprimir(arch);
  }

private:
  class Flota flota;
  int cantidad_multas_registradas;
  double total_multas_acumuladas;
};
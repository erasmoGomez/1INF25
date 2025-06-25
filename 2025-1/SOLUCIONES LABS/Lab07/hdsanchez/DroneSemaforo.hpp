#pragma once

#include "Drone.hpp"

#include <cstring>
#include <fstream>

class DroneSemaforo : public Drone {
public:
  DroneSemaforo() { luz_roja = 0; }

  ~DroneSemaforo() {}

  void set_luz_roja(int x) { luz_roja = x; }

  void leer(std::ifstream &arch) {
    Drone::leer(arch);
    char buffer[8];
    arch.getline(buffer, 8, '\n');
    set_luz_roja(strcmp(buffer, "true") == 0);
  }

  void cargar_infraccion(std::ifstream &arch) {
    Drone::cargar_infraccion(arch);
    int luz_roja_evento;
    arch >> luz_roja_evento >> std::ws;
    actualizar_infraccionI(get_cantidad_infracciones() - 1,
                           not(luz_roja_evento < luz_roja));
  }

  void imprimir(std::ofstream &arch) const { Drone::imprimir(arch); }

private:
  int luz_roja;
};
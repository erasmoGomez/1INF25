#pragma once

#include "Drone.hpp"
#include <fstream>

class DroneEstacionamiento : public Drone {
public:
  DroneEstacionamiento() { zona_carga = 0; };

  ~DroneEstacionamiento() {}

  void set_zona_carga(int x) { zona_carga = x; }

  void leer(std::ifstream &arch) {
    Drone::leer(arch);
    char buffer[8];
    arch.getline(buffer, 8, '\n');
    set_zona_carga(strcmp(buffer, "true") == 0);
  }

  void cargar_infraccion(std::ifstream &arch) {
    Drone::cargar_infraccion(arch);
    int zona_carga_evento;
    arch >> zona_carga_evento >> std::ws;
    actualizar_infraccionI(get_cantidad_infracciones() - 1,
                           not(zona_carga_evento < zona_carga));
  }

  void imprimir(std::ofstream &arch) const { Drone::imprimir(arch); }

private:
  int zona_carga;
};
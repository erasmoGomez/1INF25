#pragma once

#include "Drone.hpp"
#include <fstream>
#include <iostream>

class DroneVelocidad : public Drone {
public:
  DroneVelocidad() { velocidad_maxima_permitida = 0; }

  ~DroneVelocidad() {}

  void set_velocidad_maxima_permitida(int x) { velocidad_maxima_permitida = x; }

  void leer(std::ifstream &arch) {
    Drone::leer(arch);
    int limite;
    arch >> limite >> std::ws;
    set_velocidad_maxima_permitida(limite);
  }

  void cargar_infraccion(std::ifstream &arch) {
    Drone::cargar_infraccion(arch);
    int velocidad_registrada;
    arch >> velocidad_registrada >> std::ws;
    actualizar_infraccionI(
        get_cantidad_infracciones() - 1,
        not(velocidad_registrada < velocidad_maxima_permitida));
  }

  void imprimir(std::ofstream &arch) const { Drone::imprimir(arch); }

private:
  int velocidad_maxima_permitida;
};
#pragma once

#include "DroneEstacionamiento.hpp"
#include "DroneSemaforo.hpp"
#include "DroneVelocidad.hpp"

#include <cstring>
#include <fstream>

class Flota {
public:
  Flota() {
    n_drones_estacionamiento = 0;
    n_drones_semaforo = 0;
    n_drones_velocidad = 0;
  }

  ~Flota() {}

  void cargar_drone(std::ifstream &arch, const char *tipo) {
    if (strcmp(tipo, "Velocidad") == 0) {
      drones_velocidad[n_drones_velocidad].leer(arch);
      n_drones_velocidad += 1;
    } else if (strcmp(tipo, "Estacionamiento") == 0) {
      drones_estacionamiento[n_drones_estacionamiento].leer(arch);
      n_drones_estacionamiento += 1;
    } else if (strcmp(tipo, "Semaforo") == 0) {
      drones_semaforo[n_drones_semaforo].leer(arch);
      n_drones_semaforo += 1;
    }
  }

  int buscarDroneVelocidad(const char *id) const {
    for (int i = 0; i < n_drones_velocidad; i += 1) {
      char buffer[10];
      drones_velocidad[i].get_id(buffer);
      if (strcmp(buffer, id) == 0) {
        return i;
      }
    }
    return -1;
  }
  int buscarDroneSemaforo(const char *id) const {
    for (int i = 0; i < n_drones_semaforo; i += 1) {
      char buffer[10];
      drones_semaforo[i].get_id(buffer);
      if (strcmp(buffer, id) == 0) {
        return i;
      }
    }
    return -1;
  }
  int buscarDroneEstacionamiento(const char *id) const {
    for (int i = 0; i < n_drones_estacionamiento; i += 1) {
      char buffer[10];
      drones_estacionamiento[i].get_id(buffer);
      if (strcmp(buffer, id) == 0) {
        return i;
      }
    }
    return -1;
  }

  void actualizarDronesInfracciones(std::ifstream &arch) {
    while (true) {
      char id[20];
      arch.getline(id, 20, ',');
      if (arch.eof())
        break;
      switch (id[1]) {
      case 'V': {
        int pos = buscarDroneVelocidad(id);
        drones_velocidad[pos].cargar_infraccion(arch);
      } break;
      case 'S': {
        int pos = buscarDroneSemaforo(id);
        drones_semaforo[pos].cargar_infraccion(arch);
      } break;
      case 'E': {
        int pos = buscarDroneEstacionamiento(id);
        drones_estacionamiento[pos].cargar_infraccion(arch);
      } break;
      }
    }
  }

  int cantidad_multas_registradas() const {
    int n = 0;
    for (int i = 0; i < n_drones_velocidad; i += 1) {
      n += drones_velocidad[i].get_cantidad_infracciones();
    }
    for (int i = 0; i < n_drones_semaforo; i += 1) {
      n += drones_semaforo[i].get_cantidad_infracciones();
    }
    for (int i = 0; i < n_drones_estacionamiento; i += 1) {
      n += drones_estacionamiento[i].get_cantidad_infracciones();
    }
    return n;
  }

  double total_multas_acumuladas() const {
    double n = 0.0;
    for (int i = 0; i < n_drones_velocidad; i += 1) {
      n += drones_velocidad[i].total_multas_acumuladas();
    }
    for (int i = 0; i < n_drones_semaforo; i += 1) {
      n += drones_semaforo[i].total_multas_acumuladas();
    }
    for (int i = 0; i < n_drones_estacionamiento; i += 1) {
      n += drones_estacionamiento[i].total_multas_acumuladas();
    }
    return n;
  }

  void imprimir(std::ofstream &arch) const {
    print_delimiter(arch, '-', 120);
    arch << std::left << "Drones Velocidad:" << std::endl;
    for (int i = 0; i < n_drones_velocidad; i += 1) {
      drones_velocidad[i].imprimir(arch);
    }
    print_delimiter(arch, '-', 120);
    arch << std::left << "Drones Semaforo:" << std::endl;
    for (int i = 0; i < n_drones_semaforo; i += 1) {
      drones_semaforo[i].imprimir(arch);
    }
    print_delimiter(arch, '-', 120);
    arch << std::left << "Drones Estacionamiento:" << std::endl;
    for (int i = 0; i < n_drones_estacionamiento; i += 1) {
      drones_estacionamiento[i].imprimir(arch);
    }
  }

  static void print_delimiter(std::ofstream &arch, char c, int n) {
    for (int i = 0; i < n; i += 1) {
      arch << c;
    }
    arch << std::endl;
  }

private:
  class DroneVelocidad drones_velocidad[20];
  class DroneSemaforo drones_semaforo[20];
  class DroneEstacionamiento drones_estacionamiento[20];
  int n_drones_velocidad;
  int n_drones_semaforo;
  int n_drones_estacionamiento;
};
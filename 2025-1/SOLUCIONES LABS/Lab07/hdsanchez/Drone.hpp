#pragma once

#include "Infraccion.hpp"

#include <fstream>
#include <iomanip>
#include <iostream>

class Drone {
public:
  Drone() {
    id = nullptr;
    ubicacion = nullptr;
    capacidad = 0;
    cantidad_infracciones = 0;
  }

  ~Drone() {
    if (id != nullptr)
      delete[] id;
    if (ubicacion != nullptr)
      delete[] ubicacion;
  }

  void set_capacidad(int x) { capacidad = x; }

  int get_cantidad_infracciones() const { return cantidad_infracciones; }

  void get_id(char *cstr) const {
    if (id != nullptr) {
      strcpy(cstr, id);
    } else {
      cstr[0] = '\0';
    }
  }
  void set_id(const char *cstr) {
    if (id != nullptr)
      delete[] id;
    id = new char[strlen(cstr) + 1];
    strcpy(id, cstr);
  }

  void set_ubicacion(const char *cstr) {
    if (ubicacion != nullptr)
      delete[] ubicacion;
    ubicacion = new char[strlen(cstr) + 1];
    strcpy(ubicacion, cstr);
  }

  void leer(std::ifstream &arch) {
    char buffer[40];
    arch.getline(buffer, 40, ',');
    set_id(buffer);
    arch.getline(buffer, 40, ',');
    set_ubicacion(buffer);
    char c;
    int cap;
    arch >> cap >> c;
    set_capacidad(cap);
  }

  void cargar_infraccion(std::ifstream &arch) {
    infracciones[cantidad_infracciones].leer(arch);
    cantidad_infracciones += 1;
  }

  double total_multas_acumuladas() const {
    double n = 0.0;
    for (int i = 0; i < cantidad_infracciones; i += 1) {
      n += infracciones->get_monto();
    }
    return n;
  }

  void imprimir(std::ofstream &arch) const {
    arch << std::left << "    ID:                " << id << std::endl;
    arch << std::left << "    UBICACION:         " << ubicacion << std::endl;
    arch << std::left << "    CAPACIDAD:         " << capacidad << std::endl;
    arch << std::left << "    NRO. INFRACCIONES: " << cantidad_infracciones
         << std::endl;
    for (int i = 0; i < cantidad_infracciones; i += 1) {
      arch << "        ";
      infracciones[i].imprimir(arch);
    }
    arch << std::endl;
  }

  void actualizar_infraccionI(int pos, bool grave) {
    infracciones[pos].actualizar_infraccion(grave);
  }

private:
  char *id;
  char *ubicacion;
  int capacidad;
  int cantidad_infracciones;
  class Infraccion infracciones[20];
};
#pragma once

#include "CentralDeMonitoreo.hpp"

#include <fstream>
#include <iomanip>

class MinisterioDeTransportes {
public:
  MinisterioDeTransportes() { cantidad_centros = 0; }

  ~MinisterioDeTransportes() {
    for (int i = 0; i < cantidad_centros; i += 1) {
      if (zonas[i] != nullptr)
        delete[] zonas[i];
    }
  }

  void apertura_archivo_leer(std::ifstream &arch, const char *arch_name) {
    arch.open(arch_name, std::ios::in);
    if (not arch.is_open()) {
      std::cerr << "[ERROR] Cannot open the file: " << arch_name << std::endl;
      exit(1);
    }
  }
  void apertura_archivo_imprimir(std::ofstream &arch,
                                 const char *arch_name) const {
    arch.open(arch_name, std::ios::out);
    if (not arch.is_open()) {
      std::cerr << "[ERROR] Cannot open the file: " << arch_name << std::endl;
      exit(1);
    }
  }

  void obtener_ruta(const char *carpeta_base, const char *tipo,
                    const char *zona, char *ruta) const {
    strcpy(ruta, carpeta_base);
    strcat(ruta, "/");
    strcat(ruta, tipo);
    strcat(ruta, "_");
    strcat(ruta, zona);
    strcat(ruta, ".csv");
  }

  void leer_zonas(const char *arch_name) {
    std::ifstream arch;
    apertura_archivo_leer(arch, arch_name);
    while (true) {
      char buffer[20];
      arch >> buffer;
      if (arch.eof())
        break;
      zonas[cantidad_centros] = new char[strlen(buffer) + 1];
      strcpy(zonas[cantidad_centros], buffer);
      cantidad_centros += 1;
    }
    arch.close();
  }

  void cargar_drones(const char *carpeta_base) {
    for (int i = 0; i < cantidad_centros; i += 1) {
      char ruta[40]{};
      obtener_ruta(carpeta_base, "Drones", zonas[i], ruta);
      std::ifstream arch;
      apertura_archivo_leer(arch, ruta);
      centros[i].cargar_drones(arch);
      arch.close();
    }
  }

  void procesar_todos_los_eventos(const char *carpeta_base) {
    for (int i = 0; i < cantidad_centros; i += 1) {
      char ruta[40]{};
      obtener_ruta(carpeta_base, "Eventos", zonas[i], ruta);
      std::ifstream arch;
      apertura_archivo_leer(arch, ruta);
      centros[i].cargar_infracciones(arch);
      arch.close();
    }
  }

  void imprimir(const char *arch_name) const {
    std::ofstream arch;
    apertura_archivo_imprimir(arch, arch_name);
    print_delimiter(arch, '=', 120);
    arch << std::right << std::setw(90)
         << "REPORTE DE DRONES DEL MINISTERIO DE TRANSPORTES" << std::endl;
    for (int i = 0; i < cantidad_centros; i += 1) {
      print_delimiter(arch, '-', 120);
      arch << std::right << std::setw(60) << "Zona " << zonas[i] << std::endl;
      print_delimiter(arch, '-', 120);
      centros[i].imprimir(arch);
    }
  }

  static void print_delimiter(std::ofstream &arch, char c, int n) {
    for (int i = 0; i < n; i += 1) {
      arch << c;
    }
    arch << std::endl;
  }

private:
  class CentralDeMonitoreo centros[10];
  char *zonas[10];
  int cantidad_centros;
};
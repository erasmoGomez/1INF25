#pragma once

#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>

class Infraccion {
public:
  Infraccion() {
    fecha_evento = 0;
    tipo_infraccion = nullptr;
    monto = 0.0;
    fecha_pago_limite = 0;
    placa = nullptr;
  }

  ~Infraccion() {
    if (tipo_infraccion != nullptr)
      delete[] tipo_infraccion;
    if (placa != nullptr)
      delete[] placa;
  }

  Infraccion(const class Infraccion &other) { *this = other; }

  void operator=(const class Infraccion &other) {
    char buffer[40];
    set_fecha_evento(other.get_fecha_evento());
    other.get_tipo_infraccion(buffer);
    set_tipo_infraccion(buffer);
    set_monto(other.get_monto());
    set_fecha_pago_limite(other.get_fecha_pago_limite());
    other.get_placa(buffer);
    set_placa(buffer);
  }

  int get_fecha_evento() const { return fecha_evento; }
  void set_fecha_evento(int x) { fecha_evento = x; }

  void get_tipo_infraccion(char *cstr) const {
    if (tipo_infraccion != nullptr) {
      strcpy(cstr, tipo_infraccion);
    } else {
      cstr[0] = '\0';
    }
  }
  void set_tipo_infraccion(const char *cstr) {
    if (tipo_infraccion != nullptr)
      delete[] tipo_infraccion;
    tipo_infraccion = new char[strlen(cstr) + 1];
    strcpy(tipo_infraccion, cstr);
  }

  int get_monto() const { return monto; }
  void set_monto(double x) { monto = x; }

  int get_fecha_pago_limite() const { return fecha_pago_limite; }
  void set_fecha_pago_limite(int x) { fecha_pago_limite = x; }

  void get_placa(char *cstr) const {
    if (placa != nullptr) {
      strcpy(cstr, placa);
    } else {
      cstr[0] = '\0';
    }
  }
  void set_placa(char *cstr) {
    if (placa != nullptr)
      delete[] placa;
    placa = new char[strlen(cstr) + 1];
    strcpy(placa, cstr);
  }

  void leer(std::ifstream &arch) {
    char buffer[40], c;
    arch.getline(buffer, 40, ',');
    set_placa(buffer);
    int anho, mes, dia;
    arch >> dia >> c >> mes >> c >> anho >> c;
    fecha_evento = anho * 10000 + mes * 100 + dia;
  }

  void imprimir(std::ofstream &arch) const {
    Infraccion::imprimir_fecha(arch, fecha_evento);
    arch << "    ";
    arch << std::left << std::setw(11) << placa;
    arch << std::left << std::setw(9) << tipo_infraccion;
    arch << std::right << std::setw(6) << monto << "    ";
    Infraccion::imprimir_fecha(arch, fecha_pago_limite);
    arch << std::endl;
  }

  void actualizar_infraccion(bool grave) {
    constexpr int UIT = 5350;
    if (grave) {
      set_tipo_infraccion("Grave");
      monto = UIT * 8 / 100.;
    } else {
      set_tipo_infraccion("Leve");
      monto = UIT * 5 / 100.;
    }
    fecha_pago_limite = fecha_evento + 100;
  }

  static void imprimir_fecha(std::ofstream &arch, int fecha) {
    int anho = fecha / 10000;
    int mes = (fecha % 10000) / 100;
    int dia = fecha % 100;
    arch << std::left << std::setfill('0') << dia << '/' << mes << '/' << anho
         << std::setfill(' ');
  }

private:
  int fecha_evento;
  char *tipo_infraccion;
  double monto;
  int fecha_pago_limite;
  char *placa;
};
#include "MinisterioDeTransporte.hpp"

#include "Infraccion.hpp"
#include "Multa.hpp"

#include <cstring>
#include <fstream>
#include <iostream>

MinisterioDeTransporte::MinisterioDeTransporte() {
  infracciones = nullptr;
  numInf = 0;
  numEmp = 0;
}

MinisterioDeTransporte::~MinisterioDeTransporte() {
  if (infracciones != nullptr) {
    delete[] infracciones;
  }
}

int MinisterioDeTransporte::getNumInf() const { return numInf; }

void MinisterioDeTransporte::setNumInf(int x) { numInf = x; }

int MinisterioDeTransporte::getNumEmp() const { return numEmp; }

void MinisterioDeTransporte::setNumEmp(int x) { numEmp = x; }

double MinisterioDeTransporte::buscarMontoDeMulta(int codigo) const {
  for (int i = 0; i < numInf; i += 1) {
    if (infracciones[i].getCodigo() == codigo) {
      return infracciones[i].getMulta();
    }
  }
  return 0.0;
}

void MinisterioDeTransporte::agregarMultaAEmpresa(const class Multa &multa) {
  char placa[9];
  multa.getPlaca(placa);
  for (int i = 0; i < numEmp; i += 1) {
    for (int j = 0; j < empresas[i].getNumPlacas(); j += 1) {
      char placa2[9];
      empresas[i].getPlacaI(placa2, j);
      if (strcmp(placa2, placa) == 0) {
        empresas[i] += multa;
        return;
      }
    }
  }
}

void MinisterioDeTransporte::operator<(const char *arch_name) {
  std::ifstream arch;
  arch.open(arch_name, std::ios::in);
  if (not arch.is_open()) {
    std::cerr << "[ERROR] Cannot open the file: " << arch_name << std::endl;
    exit(1);
  }

  class Infraccion infracciones_tmp[150]{};
  while (true) {
    if (not(arch >> infracciones_tmp[numInf])) {
      break;
    }
    numInf += 1;
  }
  infracciones = new class Infraccion[numInf];
  for (int i = 0; i < numInf; i += 1) {
    infracciones[i] = infracciones_tmp[i];
  }
}

void MinisterioDeTransporte::operator<=(const char *arch_name) {
  std::ifstream arch;
  arch.open(arch_name, std::ios::in);
  if (not arch.is_open()) {
    std::cerr << "[ERROR] Cannot open the file: " << arch_name << std::endl;
    exit(1);
  }

  while (true) {
    if (not(arch >> empresas[numEmp])) {
      break;
    }
    numEmp += 1;
  }
}

void MinisterioDeTransporte::operator<<=(const char *arch_name) {
  std::ifstream arch;
  arch.open(arch_name, std::ios::in);
  if (not arch.is_open()) {
    std::cerr << "[ERROR] Cannot open the file: " << arch_name << std::endl;
    exit(1);
  }

  class Multa multa;
  while (true) {
    if (not(arch >> multa)) {
      break;
    }
    multa.setMulta(buscarMontoDeMulta(multa.getCodigoInfraccion()));
    agregarMultaAEmpresa(multa);
  }
}

static void print_repeated_c(std::ofstream &arch, char c, int n) {
  for (int i = 0; i < n; i += 1) {
    arch << c;
  }
  arch << std::endl;
}

void MinisterioDeTransporte::operator>>(const char *arch_name) {
  std::ofstream arch;
  arch.open(arch_name, std::ios::out);
  if (not arch.is_open()) {
    std::cerr << "[ERROR] Cannot open the file: " << arch_name << std::endl;
    exit(1);
  }

  arch << "                                MINISTERIO DE TRANSPORTE"
       << std::endl;
  print_repeated_c(arch, '=', 120);
  arch << "                                 TABLA DE INFRACCIONES" << std::endl;
  print_repeated_c(arch, '-', 120);
  arch << "  CODIGO   MULTA    GRAVEDAD    DESCRIPCION" << std::endl;
  print_repeated_c(arch, '-', 120);
  for (int i = 0; i < numInf; i += 1) {
    arch << infracciones[i];
  }
  print_repeated_c(arch, '=', 120);
  arch << "                     RELACION DE EMPRESAS CON INFRACCIONES DE "
          "TRANSITO"
       << std::endl;
  print_repeated_c(arch, '-', 120);
  arch << "  DNI        NOMBRE                                  PLACAS DE SUS "
          "VEHICULOS"
       << std::endl;
  print_repeated_c(arch, '-', 120);
  for (int i = 0; i < numEmp; i += 1) {
    arch << empresas[i];
  }
  print_repeated_c(arch, '=', 120);
}
#include "Multa.hpp"

#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>

Multa::Multa() {
  placa = nullptr;
  fechaDeInfraccion = 0;
  fechaDePago = 0;
  codigoInfraccion = 0;
  multa = 0.0;
}

Multa::~Multa() {
  if (placa != nullptr) {
    delete[] placa;
  }
}

Multa::Multa(const class Multa &orig) { *this = orig; }

void Multa::operator=(const class Multa &orig) {
  char buffer[9];
  orig.getPlaca(buffer);
  setPlaca(buffer);
  setFechaDeInfraccion(orig.getFechaDeInfraccion());
  setFechaDePago(orig.getFechaDePago());
  setCodigoInfraccion(orig.getCodigoInfraccion());
  setMulta(orig.getMulta());
}

void Multa::getPlaca(char *cstr) const {
  if (placa != nullptr) {
    strcpy(cstr, placa);
  } else {
    cstr[0] = '\0';
  }
}

void Multa::setPlaca(char *cstr) {
  if (placa != nullptr) {
    delete[] placa;
  }
  placa = new char[strlen(cstr) + 1];
  strcpy(placa, cstr);
}

int Multa::getFechaDeInfraccion() const { return fechaDeInfraccion; }

void Multa::setFechaDeInfraccion(int x) { fechaDeInfraccion = x; }

int Multa::getFechaDePago() const { return fechaDePago; }

void Multa::setFechaDePago(int x) { fechaDePago = x; }

int Multa::getCodigoInfraccion() const { return codigoInfraccion; }

void Multa::setCodigoInfraccion(int x) { codigoInfraccion = x; }

double Multa::getMulta() const { return multa; }

void Multa::setMulta(double x) { multa = x; }

static void printFecha(std::ofstream &arch, int fecha) {
  int anho = fecha / 10000;
  int mes = (fecha % 10000) / 100;
  int day = fecha % 100;
  arch << std::right << std::setw(2) << std::setfill('0') << day << '/';
  arch << std::setw(2) << std::setfill('0') << mes << '/';
  arch << std::setw(4) << std::setfill('0') << anho;
  arch << std::setfill(' ');
}

void Multa::printFechaDeInfraccion(std::ofstream &arch) const {
  printFecha(arch, fechaDeInfraccion);
}

void Multa::printFechaDePago(std::ofstream &arch) const {
  printFecha(arch, fechaDePago);
}

bool operator>>(std::ifstream &arch, class Multa &mul) {
  char c;
  int dia, mes, anho, fecha;
  char placa[9];
  int codigo;
  arch >> dia;
  if (arch.eof())
    return false;
  arch >> c >> mes >> c >> anho >> c;
  fecha = anho * 10000 + mes * 100 + dia;
  mul.setFechaDeInfraccion(fecha);
  arch.getline(placa, 9, ',');
  mul.setPlaca(placa);
  arch >> codigo;
  mul.setCodigoInfraccion(codigo);
  if (arch.get() == ',') {
    arch.get(); // 'P'
    arch >> c >> dia >> c >> mes >> c >> anho;
    fecha = anho * 10000 + mes * 100 + dia;
    mul.setFechaDePago(fecha);
  }
  arch >> std::ws;
  return true;
}

void operator<<(std::ofstream &arch, const class Multa &mul) {
  char placa[9];
  mul.getPlaca(placa);
  arch << std::left << std::setw(14) << placa;
  mul.printFechaDeInfraccion(arch);
  arch << std::right << std::setw(20) << mul.getCodigoInfraccion() << "      ";
  arch << std::right << std::setw(12) << mul.getMulta();
  if (mul.getFechaDePago() != 0) {
    arch << "      ";
    mul.printFechaDePago(arch);
  }
  arch << std::endl;
}

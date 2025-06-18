#include "Infraccion.hpp"

#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>

Infraccion::Infraccion() {
  codigo = 0;
  descripcion = nullptr;
  gravedad = nullptr;
  multa = 0.0;
}

Infraccion::~Infraccion() {
  if (descripcion != nullptr) {
    delete[] descripcion;
  }
  if (gravedad != nullptr) {
    delete[] gravedad;
  }
}

Infraccion::Infraccion(const class Infraccion &orig) { *this = orig; }

void Infraccion::operator=(const class Infraccion &orig) {
  char buffer[180];
  setCodigo(orig.getCodigo());
  orig.getDescripcion(buffer);
  setDescripcion(buffer);
  orig.getGravedad(buffer);
  setGravedad(buffer);
  setMulta(orig.getMulta());
}

int Infraccion::getCodigo() const { return codigo; }

void Infraccion::setCodigo(int x) { codigo = x; }

void Infraccion::getDescripcion(char *cstr) const {
  if (descripcion != nullptr) {
    strcpy(cstr, descripcion);
  } else {
    cstr[0] = '\0';
  }
}

void Infraccion::setDescripcion(char *cstr) {
  if (descripcion != nullptr) {
    delete[] descripcion;
  }
  descripcion = new char[strlen(cstr) + 1];
  strcpy(descripcion, cstr);
}

void Infraccion::getGravedad(char *cstr) const {
  if (gravedad != nullptr) {
    strcpy(cstr, gravedad);
  } else {
    cstr[0] = '\0';
  }
}

void Infraccion::setGravedad(char *cstr) {
  if (gravedad != nullptr) {
    delete[] gravedad;
  }
  gravedad = new char[strlen(cstr) + 1];
  strcpy(gravedad, cstr);
}

double Infraccion::getMulta() const { return multa; }

void Infraccion::setMulta(double x) { multa = x; }

bool operator>>(std::ifstream &arch, class Infraccion &inf) {
  char c;
  int codigo;
  double multa;
  arch >> codigo;
  if (arch.eof())
    return false;
  inf.setCodigo(codigo);
  arch >> c >> multa >> c;
  inf.setMulta(multa);
  char buffer[180];
  arch.getline(buffer, 180, ',');
  inf.setGravedad(buffer);
  arch.getline(buffer, 180, '\n');
  inf.setDescripcion(buffer);
  // std::cout << buffer << std::endl;
  return true;
}

void operator<<(std::ofstream &arch, const class Infraccion &inf) {
  char buffer[180];
  arch << std::setprecision(2) << std::fixed;
  arch << std::right << std::setw(6) << inf.getCodigo();
  arch << std::right << std::setw(11) << inf.getMulta() << "   ";
  inf.getGravedad(buffer);
  arch << std::setw(12) << std::left << buffer;
  inf.getDescripcion(buffer);
  arch << std::setw(60) << std::left << buffer;
  arch << std::endl;
}

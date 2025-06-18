#include "Empresa.hpp"

#include "Multa.hpp"

#include <cstring>
#include <iostream>

Empresa::Empresa() {
  dni = 0;
  nombre = nullptr;
  for (int i = 0; i < 10; i += 1) {
    placas[i] = nullptr;
  }
  numPlacas = 0;
  numMultas = 0;
}

Empresa::~Empresa() {
  if (nombre != nullptr) {
    delete[] nombre;
  }
  for (int i = 0; i < 10; i += 1) {
    if (placas[i] != nullptr) {
      delete[] placas[i];
    }
  }
}

int Empresa::getDni() const { return dni; }

void Empresa::setDni(int x) { dni = x; }

void Empresa::getNombre(char *cstr) const {
  if (nombre != nullptr) {
    strcpy(cstr, nombre);
  } else {
    cstr[0] = '\0';
  }
}

void Empresa::setNombre(char *cstr) {
  if (nombre != nullptr) {
    delete[] nombre;
  }
  nombre = new char[strlen(cstr) + 1];
  strcpy(nombre, cstr);
}

int Empresa::getNumPlacas() const { return numPlacas; }

void Empresa::setNumPlacas(int x) { numPlacas = x; }

int Empresa::getNumMultas() const { return numMultas; }

void Empresa::setNumMultas(int x) { numMultas = x; }

void Empresa::getPlacaI(char *cstr, int idx) const {
  if (placas[idx] != nullptr) {
    strcpy(cstr, placas[idx]);
  } else {
    cstr[0] = '\0';
  }
}

void Empresa::setPlacaI(char *cstr, int idx) {
  if (placas[idx] != nullptr) {
    delete[] placas[idx];
  }
  placas[idx] = new char[strlen(cstr) + 1];
  strcpy(placas[idx], cstr);
}

void Empresa::operator+=(const class Multa &multa) {
  multas[numMultas] = multa;
  numMultas += 1;
}

void Empresa::printMultaI(std::ofstream &arch, int idx) const {
  arch << multas[idx];
}

bool operator>>(std::ifstream &arch, class Empresa &emp) {
  char nombre[60];
  char c;
  int dni;
  arch >> dni;
  if (arch.eof())
    return false;
  emp.setDni(dni);
  arch >> c;
  arch.getline(nombre, 60, ',');
  emp.setNombre(nombre);
  int i = 0;
  char placa[9];
  while (true) {
    arch.get(placa, 9);
    emp.setPlacaI(placa, i);
    i += 1;
    emp.setNumPlacas(i);
    if (arch.get() == '\n')
      break;
  }
  return true;
}

void operator<<(std::ofstream &arch, const class Empresa &emp) {
  char buffer[120];
  arch << std::right << std::setw(10) << emp.getDni() << "   ";
  emp.getNombre(buffer);
  arch << std::setw(40) << std::left << buffer;
  for (int i = 0; i < emp.getNumPlacas(); i += 1) {
    char placa[9];
    emp.getPlacaI(placa, i);
    arch << std::setw(11) << std::left << placa;
  }
  arch << std::endl;
  if (emp.getNumMultas() > 0) {
    arch << "     Placa    Fecha de infraccion    Codigo de infraccion    "
            "Multa    Fecha de pago"
         << std::endl;
  }
  for (int i = 0; i < emp.getNumMultas(); i += 1) {
    arch << "    ";
    emp.printMultaI(arch, i);
  }
  arch << std::endl;
}

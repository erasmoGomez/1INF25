#pragma once

#include "Multa.hpp"

#include <fstream>

class Empresa {
public:
  Empresa();
  ~Empresa();

  int getDni() const;
  void setDni(int);
  void getNombre(char *) const;
  void setNombre(char *);
  int getNumPlacas() const;
  void setNumPlacas(int);
  int getNumMultas() const;
  void setNumMultas(int);

  void getPlacaI(char *, int) const;
  void setPlacaI(char *, int);

  void operator+=(const class Multa &);

  void printMultaI(std::ofstream &, int) const;

private:
  int dni;
  char *nombre;
  char *placas[10];
  int numPlacas;
  class Multa multas[100];
  int numMultas;
};

bool operator>>(std::ifstream &arch, class Empresa &emp);

void operator<<(std::ofstream &arch, const class Empresa &emp);

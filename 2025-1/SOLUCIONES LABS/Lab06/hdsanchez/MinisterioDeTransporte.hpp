#pragma once

#include "Empresa.hpp"
#include "Infraccion.hpp"
#include "Multa.hpp"

class MinisterioDeTransporte {
public:
  MinisterioDeTransporte();
  ~MinisterioDeTransporte();

  int getNumInf() const;
  void setNumInf(int);
  int getNumEmp() const;
  void setNumEmp(int);

  void operator<(const char *arch_name);
  void operator<=(const char *arch_name);
  void operator<<=(const char *arch_name);
  void operator>>(const char *arch_name);

private:
  double buscarMontoDeMulta(int) const;
  void agregarMultaAEmpresa(const class Multa &);

  class Infraccion *infracciones;
  int numInf;
  class Empresa empresas[50];
  int numEmp;
};

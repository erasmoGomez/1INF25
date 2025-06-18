#pragma once

#include <fstream>

class Multa {
public:
  Multa();
  ~Multa();
  Multa(const class Multa &);

  void operator=(const class Multa &);

  void getPlaca(char *) const;
  void setPlaca(char *);
  int getFechaDeInfraccion() const;
  void setFechaDeInfraccion(int);
  int getFechaDePago() const;
  void setFechaDePago(int);
  int getCodigoInfraccion() const;
  void setCodigoInfraccion(int);
  double getMulta() const;
  void setMulta(double);

  void printFechaDeInfraccion(std::ofstream &arch) const;
  void printFechaDePago(std::ofstream &arch) const;

private:
  char *placa;
  int fechaDeInfraccion;
  int fechaDePago;
  int codigoInfraccion;
  double multa;
};

bool operator>>(std::ifstream &arch, class Multa &mul);

void operator<<(std::ofstream &arch, const class Multa &mul);

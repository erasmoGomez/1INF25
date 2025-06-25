#pragma once

#include <fstream>

class Infraccion {
public:
  Infraccion();
  ~Infraccion();
  Infraccion(const class Infraccion &);

  void operator=(const class Infraccion &);

  int getCodigo() const;
  void setCodigo(int);
  void getDescripcion(char *) const;
  void setDescripcion(char *);
  void getGravedad(char *) const;
  void setGravedad(char *);
  double getMulta() const;
  void setMulta(double);

private:
  int codigo;
  char *descripcion;
  char *gravedad;
  double multa;
};

bool operator>>(std::ifstream &arch, class Infraccion &inf);

void operator<<(std::ofstream &arch, const class Infraccion &inf);

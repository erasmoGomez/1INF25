#include "BibliotecaRegistros.hpp"

#include <fstream>
#include <iomanip>

using namespace std;

void *leeregistro(ifstream &arch) {
  char c;

  // Licencia
  int *licencia = new int;
  arch >> *licencia;
  if (arch.eof()) {
    return nullptr;
  }
  arch.get();

  // Placa
  char placa_buffer[8];
  arch.getline(placa_buffer, 8, ',');
  char *placa = new char[strlen(placa_buffer) + 1];
  strcpy(placa, placa_buffer);

  // Fecha
  char fecha_buffer[20];
  arch.getline(fecha_buffer, 20, ',');
  char *fecha = new char[strlen(fecha_buffer) + 1];
  strcpy(fecha, fecha_buffer);

  // Infraccion
  int *infraccion = new int;
  arch >> *infraccion >> c;

  // Nombre
  char nombre_buffer[40];
  arch.getline(nombre_buffer, 40, '\n');
  char *nombre = new char[strlen(nombre_buffer) + 1];
  strcpy(nombre, nombre_buffer);

  void **reg = new void *[5] {};
  reg[0] = licencia;
  reg[1] = placa;
  reg[2] = fecha;
  reg[3] = infraccion;
  reg[4] = nombre;
  return reg;
}

int clasificaregistro(void *dato) {
  void **reg = (void **)dato;
  int *infraccion_ptr = (int *)reg[3];
  int infraccion = *infraccion_ptr;
  return ((infraccion / 100) == 1) ? 1 : 2;
}

void imprimeregistro(ofstream &arch, void *dato) {
  void **reg = (void **)dato;
  int *licencia = (int *)reg[0];
  char *fecha = (char *)reg[2];
  int *infraccion = (int *)reg[3];
  char *nombre = (char *)reg[4];
  arch << setw(12) << fecha;
  arch << setw(12) << *licencia;
  arch << setw(40) << nombre;
  arch << setw(4) << *infraccion << endl;
}

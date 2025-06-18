#include "BibliotecaEnteros.hpp"

#include <fstream>

using namespace std;

void *leenum(ifstream &arch) {
  int *num = new int;
  arch >> *num;
  if (arch.eof()) {
    return nullptr;
  }
  arch >> ws;
  return (void *)num;
}

int clasificaentero(void *dato) {
  int *num = (int *)dato;
  return (*num < 10) ? 1 : 2;
}

void imprimenum(ofstream &arch, void *dato) {
  int *num = (int *)dato;
  arch << *num << endl;
}

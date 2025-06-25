#include "BibliotecaEnteros.hpp"
#include "BibliotecaGenerica.hpp"
#include "BibliotecaRegistros.hpp"

int main(int arg, char *argv[]) {
  void *lista;
  creaLista(lista, leenum, clasificaentero, "numeros.txt");
  imprimeLista(lista, imprimenum, "Repnum.txt");

  creaLista(lista, leenum, clasificaentero, "numeros2.txt");
  imprimeLista(lista, imprimenum, "Repnum2.txt");

  creaLista(lista, leeregistro, clasificaregistro, "RegistroDeFaltas1.csv");
  imprimeLista(lista, imprimeregistro, "Repfalta.txt");

  return 0;
}
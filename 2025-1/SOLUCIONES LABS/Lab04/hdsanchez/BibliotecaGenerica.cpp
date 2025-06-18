#include "BibliotecaGenerica.hpp"

#include <fstream>
#include <iostream>

using namespace std;

enum CABEZA { BLOQUE1 = 0, BLOQUE2 = 1 };

enum NODO { DATO = 0, SIGUIENTE = 1 };

void generaLista(void *&lista) {
  void **cabeza = new void *[2] {};

  void **inicio_bloque_2 = new void *[2] {};
  inicio_bloque_2[DATO] = nullptr;
  inicio_bloque_2[SIGUIENTE] = nullptr;

  void **inicio_bloque_1 = new void *[2] {};
  inicio_bloque_1[DATO] = nullptr;
  inicio_bloque_1[SIGUIENTE] = inicio_bloque_2;

  cabeza[BLOQUE1] = inicio_bloque_1;
  cabeza[BLOQUE2] = inicio_bloque_2;

  lista = cabeza;
}

bool bloque_vacio(void **inicio_bloque) {
  return inicio_bloque[DATO] == nullptr;
}

void insertaBloque(void **inicio_bloque, void *dato, void *stop) {
  void **anterior = inicio_bloque;
  while (anterior[SIGUIENTE] != stop) {
    anterior = (void **)anterior[SIGUIENTE];
  }
  void **nuevo_nodo = new void *[2] {};
  nuevo_nodo[SIGUIENTE] = stop;
  nuevo_nodo[DATO] = dato;
  anterior[SIGUIENTE] = nuevo_nodo;
}

void insertaLista(void *lista, int (*clasifica)(void *), void *dato) {
  void **cabeza = (void **)lista;
  int num_bloque = clasifica(dato);
  void **inicio_bloque = (void **)(cabeza[num_bloque - 1]);
  if (bloque_vacio(inicio_bloque)) {
    inicio_bloque[DATO] = dato;
  } else {
    insertaBloque(inicio_bloque, dato,
                  (num_bloque == 1) ? cabeza[BLOQUE2] : nullptr);
  }
}

void creaLista(void *&lista, void *(*lee)(ifstream &arch),
               int (*clasifica)(void *), const char *arch_name) {

  ifstream arch;
  arch.open(arch_name, ios::in);
  if (not arch.is_open()) {
    cerr << "[ERROR] Cannot open the file: " << arch_name << endl;
    exit(1);
  }

  generaLista(lista);
  while (true) {
    void *dato = lee(arch);
    if (dato == nullptr) {
      break;
    }
    insertaLista(lista, clasifica, dato);
  }
}

void imprimeLista(void *lista, void (*imprime)(ofstream &arch, void *dato),
                  const char *arch_name) {
  ofstream arch;
  arch.open(arch_name, ios::out);
  if (not arch.is_open()) {
    cerr << "[ERROR] Cannot open the file: " << arch_name << endl;
    exit(1);
  }

  void **cabeza = (void **)lista;
  void **nodo = (void **)cabeza[BLOQUE1];
  while (nodo != nullptr) {
    if (nodo[DATO] != nullptr) {
      imprime(arch, nodo[DATO]);
    }
    nodo = (void **)nodo[SIGUIENTE];
  }
}
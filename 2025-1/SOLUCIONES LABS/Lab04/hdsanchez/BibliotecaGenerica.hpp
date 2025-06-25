#pragma once

#include <fstream>

using namespace std;

void creaLista(void *&lista, void *(*lee)(ifstream &arch),
               int (*clasifica)(void *), const char *arch_name);

void imprimeLista(void *lista, void (*imprime)(ofstream &arch, void *dato),
                  const char *arch_name);
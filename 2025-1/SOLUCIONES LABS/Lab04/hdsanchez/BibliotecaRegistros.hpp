#pragma once

#include <fstream>

using namespace std;

void *leeregistro(ifstream &arch);

int clasificaregistro(void *dato);

void imprimeregistro(ofstream &arch, void *dato);
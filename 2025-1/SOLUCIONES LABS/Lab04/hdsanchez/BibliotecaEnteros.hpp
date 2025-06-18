#pragma once

#include <fstream>

using namespace std;

void *leenum(ifstream &arch);

int clasificaentero(void *dato);

void imprimenum(ofstream &arch, void *dato);
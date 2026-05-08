//
// Created by Daniel Sanchez on 8/05/26.
//

#ifndef SOLUCION_INTEGERS_H
#define SOLUCION_INTEGERS_H

#include <fstream>

void *leenum(std::ifstream &file);

int comparanum(const void *a, const void *b);

int verificanum(const void *a, const void *b);

void imprimenum(std::ostream &file, void *data);

#endif //SOLUCION_INTEGERS_H

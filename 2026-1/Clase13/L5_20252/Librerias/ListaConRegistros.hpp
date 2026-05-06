//
// Created by erasmo on 5/5/26.
//

#ifndef L5_20252_LISTACONREGISTROS_HPP
#define L5_20252_LISTACONREGISTROS_HPP

#include "Utils.hpp"

void *leeregistros(ifstream &);

void *leeordenes(ifstream &);

bool compruebaregistro(void *, void *);

void imprimeregistros(ofstream &, void *, void *);

#endif //L5_20252_LISTACONREGISTROS_HPP

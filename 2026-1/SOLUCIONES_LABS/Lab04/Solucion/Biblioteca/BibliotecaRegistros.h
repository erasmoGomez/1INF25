//
// Created by Daniel Sanchez on 8/05/26.
//

#ifndef SOLUCION_BIBLIOTECAREGISTROS_H
#define SOLUCION_BIBLIOTECAREGISTROS_H

#include <fstream>

enum REGISTRO {
    CODIGO = 0,
    FECHA,
    MOTIVO,
    HORA,
    ESTADO,
    NOMBRE,
    RAZA,
    COLOR,
    ESPECIE,
    REGISTRO_COUNT,
};

void *leeregistro(std::ifstream &file);

int comparareg(const void *a, const void *b);

int verificareg(const void *a, const void *b);

void imprimeregistro(std::ostream &file, void *data);

#endif //SOLUCION_BIBLIOTECAREGISTROS_H

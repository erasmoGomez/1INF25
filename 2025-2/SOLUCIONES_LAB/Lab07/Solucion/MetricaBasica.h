//
// Created by Daniel Sanchez on 7/11/25.
//

#ifndef SOLUCION_METRICABASICA_H
#define SOLUCION_METRICABASICA_H

#include "Metrica.h"

#include <fstream>

class MetricaBasica : public Metrica {
private:
    double horas_transmitidas;
    int espectadores_promedio;

public:
    MetricaBasica();

    MetricaBasica &operator=(const MetricaBasica &m);

    double get_horas_transmitidas() const;

    void set_horas_transmitidas(double x);

    int get_espectadores_promedio() const;

    void set_espectadores_promedio(int x);

    void leer(std::ifstream &arch);

    std::ostream &imprimir(std::ostream &arch) const;
};


#endif //SOLUCION_METRICABASICA_H

//
// Created by Daniel Sanchez on 7/11/25.
//

#ifndef SOLUCION_METRICACALIDAD_H
#define SOLUCION_METRICACALIDAD_H

#include "Metrica.h"

#include <fstream>

class MetricaCalidad : public Metrica {
private:
    int bitrate_promedio_kbps;
    double porcentaje_frames_perdidos;
    int fps_promedio;

public:
    MetricaCalidad();

    MetricaCalidad &operator=(const MetricaCalidad &m);

    int get_bitrate_promedio_kbps() const;

    void set_bitrate_promedio_kbps(int x);

    double get_porcentaje_frames_perdidos() const;

    void set_porcentaje_frames_perdidos(double x);

    int get_fps_promedio() const;

    void set_fps_promedio(int x);

    void leer(std::ifstream &arch);

    std::ostream & imprimir(std::ostream &arch) const;
};


#endif //SOLUCION_METRICACALIDAD_H

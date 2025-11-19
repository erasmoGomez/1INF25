//
// Created by Daniel Sanchez on 7/11/25.
//

#ifndef SOLUCION_STREAMERGRATUITO_H
#define SOLUCION_STREAMERGRATUITO_H

#include "Streamer.h"

#include "MetricaBasica.h"

#include <fstream>

class StreamerGratuito : public Streamer {
private:
    int fecha_fin_trial;
    MetricaBasica *metricas_basicas;
    int cantidad_metricas_basicas;

public:
    StreamerGratuito();

    ~StreamerGratuito();

    StreamerGratuito &operator=(const StreamerGratuito &);

    int get_fecha_fin_trial() const;

    void set_fecha_fin_trial(int n);

    int get_cantidad_metricas_basicas() const;

    void set_cantidad_metricas_basicas(int n);

    void leer(std::ifstream &arch);

    void leer_metrica_basica(std::ifstream &arch);

    void imprimir(std::ostream &arch);

private:
    int get_metricas_basicas_activas() const;

    int get_metricas_basicas_expiradas() const;

    double get_horas_transmitidas() const;

    int get_viewers_prom() const;
};


#endif //SOLUCION_STREAMERGRATUITO_H

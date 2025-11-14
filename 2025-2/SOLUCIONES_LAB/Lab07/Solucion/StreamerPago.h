//
// Created by Daniel Sanchez on 7/11/25.
//

#ifndef SOLUCION_STREAMERPAGO_H
#define SOLUCION_STREAMERPAGO_H

#include "Streamer.h"
#include "MetricaBasica.h"
#include "MetricaCalidad.h"
#include "MetricaEngagement.h"

#include <fstream>

class StreamerPago : public Streamer {
private:
    int fecha_inicio_plan;
    MetricaBasica *metricas_basicas;
    int cantidad_metricas_basicas;
    MetricaCalidad *metricas_calidad;
    int cantidad_metricas_calidad;
    MetricaEngagement *metricas_engagement;
    int cantidad_metricas_engagement;

public:
    StreamerPago();

    ~StreamerPago();

    StreamerPago &operator=(const StreamerPago &);

    int get_fecha_inicio_plan() const;

    void set_fecha_inicio_plan(int n);

    int get_cantidad_metricas_basicas() const;

    void set_cantidad_metricas_basicas(int n);

    int get_cantidad_metricas_calidad() const;

    void set_cantidad_metricas_calidad(int n);

    int get_cantidad_metricas_engagement() const;

    void set_cantidad_metricas_engagement(int n);

    void leer_metrica_basica(std::ifstream &arch);

    void leer_metrica_calidad(std::ifstream &arch);

    void leer_metrica_engagement(std::ifstream &arch);

    void leer(std::ifstream &arch);

    void imprimir(std::ostream &arch);

private:
    int get_metricas_basicas_activas() const;

    int get_metricas_calidad_activas() const;

    int get_metricas_engagement_activas() const;

    int get_metricas_activas() const;

    int get_metricas_basicas_expiradas() const;

    int get_metricas_calidad_expiradas() const;

    int get_metricas_engagement_expiradas() const;

    int get_metricas_expiradas() const;

    double get_horas_transmitidas() const;

    int get_viewers_prom() const;

    int get_chat_msgs() const;

    int get_chatters_unicos() const;

    int get_clips() const;

    int get_bitrate_prom() const;

    double get_drop_prom() const;

    int get_fps_prom() const;
};


#endif //SOLUCION_STREAMERPAGO_H

//
// Created by Daniel Sanchez on 7/11/25.
//

#ifndef SOLUCION_GESTORSTREAMERS_H
#define SOLUCION_GESTORSTREAMERS_H

#include "StreamerGratuito.h"
#include "StreamerPago.h"

#define FECHA_REPORTE 20251107

class GestorStreamers {
    StreamerGratuito *streamers_gratuitos;
    StreamerPago *streamers_pagados;
    int cantidad_gratuitos;
    int cantidad_pagados;

public:
    GestorStreamers();

    ~GestorStreamers();

    void cargar_datos_streamers(const char *arch_nom);

    void actualizar_datos_metricas(const char *arch_nom);

    void generar_reportes() const;

private:
    void agregar_metrica_streamer(int streamer_id, const char *tipo, std::ifstream &arch);

    static char *generar_nombre_reporte(const char *tipo, const char *cuenta, const char *categoria);
};


#endif //SOLUCION_GESTORSTREAMERS_H

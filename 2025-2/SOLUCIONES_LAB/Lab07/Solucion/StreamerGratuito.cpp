//
// Created by Daniel Sanchez on 7/11/25.
//

#include "StreamerGratuito.h"

#include "GestorStreamers.h"
#include "Streamer.h"
#include "Utils.h"

#include <fstream>
#include <iostream>

StreamerGratuito::StreamerGratuito() {
    fecha_fin_trial = 0;
    metricas_basicas = nullptr;
    cantidad_metricas_basicas = 0;
}

StreamerGratuito::~StreamerGratuito() {
    delete[] metricas_basicas;
}

StreamerGratuito &StreamerGratuito::operator=(const StreamerGratuito &other) {
    if (&other == this) {
        return *this;
    }
    Streamer::operator=(other);
    set_fecha_fin_trial(other.fecha_fin_trial);
    set_cantidad_metricas_basicas(other.cantidad_metricas_basicas);
    for (int i = 0; i < other.cantidad_metricas_basicas; i++) {
        metricas_basicas[i] = other.metricas_basicas[i];
    }
    return *this;
}

int StreamerGratuito::get_fecha_fin_trial() const {
    return fecha_fin_trial;
}

void StreamerGratuito::set_fecha_fin_trial(int n) {
    fecha_fin_trial = n;
}

int StreamerGratuito::get_cantidad_metricas_basicas() const {
    return cantidad_metricas_basicas;
}

void StreamerGratuito::set_cantidad_metricas_basicas(int n) {
    cantidad_metricas_basicas = n;
}

void StreamerGratuito::leer(std::ifstream &arch) {
    Streamer::leer(arch);
    fecha_fin_trial = leer_fecha(arch);
    arch >> std::ws;
}

void StreamerGratuito::leer_metrica_basica(std::ifstream &arch) {
    if (metricas_basicas == nullptr) {
        metricas_basicas = new MetricaBasica[MAX_METRICS_COUNT]{};
    }
    metricas_basicas[cantidad_metricas_basicas].leer(arch);
    cantidad_metricas_basicas++;
}

void StreamerGratuito::imprimir(std::ostream &arch) {
    imprimir_sep(arch, 80, '=');
    arch << std::setw(50) << std::right << "REPORTE DE STREAMERS" << std::endl;
    imprimir_sep(arch, 80, '=');

    Streamer::imprimir(arch);
    arch << "TIPO: StreamerGratuito" << std::endl;
    imprimir_sep(arch, 80, '-');

    if (cantidad_metricas_basicas > 0) {
        arch << std::setprecision(2) << std::fixed;
        arch << "[BASIC] HORAS_TOT: " << std::setw(6) << get_horas_transmitidas() << " | ";
        arch << "VIEWERS_PROM_GLOBAL: " << std::setw(4) << get_viewers_prom() << " | ";
        arch << "ACTIVAS: " << get_metricas_basicas_activas() << " | ";
        arch << "EXPIRADAS: " << get_metricas_basicas_expiradas() << std::endl;
        arch << "  Código    Fecha Calc.    Expira    Estado    Horas    Viewers     Descripción" << std::endl;
        for (int i = 0; i < cantidad_metricas_basicas; i++) {
            arch << "  ";
            metricas_basicas[i].imprimir(arch);
        }
    }

    imprimir_sep(arch, 80, '-');
    arch << "[UPSELL] Funcionalidad Prop. Adquiere la licencia para ver estadísticas avanzadas." << std::endl;
    imprimir_sep(arch, 80, '-');

    arch << "[TOTAL] MÉTRICAS ACTIVAS: " << get_metricas_basicas_activas() << " | ";
    arch << "MÉTRICAS EXPIRADAS: " << get_metricas_basicas_expiradas() << " | ";
    arch << "FECHA DE REPORTE: ";
    imprimir_fecha(arch, FECHA_REPORTE) << std::endl;
    imprimir_sep(arch, 80, '=');
}

int StreamerGratuito::get_metricas_basicas_activas() const {
    int res = 0;
    for (int i = 0; i < cantidad_metricas_basicas; i++) {
        res += (metricas_basicas[i].get_estado()) ? 1 : 0;
    }
    return res;
}

int StreamerGratuito::get_metricas_basicas_expiradas() const {
    int res = 0;
    for (int i = 0; i < cantidad_metricas_basicas; i++) {
        res += (metricas_basicas[i].get_estado()) ? 0 : 1;
    }
    return res;
}

double StreamerGratuito::get_horas_transmitidas() const {
    double res = 0;
    for (int i = 0; i < cantidad_metricas_basicas; i++) {
        res += metricas_basicas[i].get_horas_transmitidas();
    }
    return res;
}

int StreamerGratuito::get_viewers_prom() const {
    int res = 0;
    for (int i = 0; i < cantidad_metricas_basicas; i++) {
        res += metricas_basicas[i].get_espectadores_promedio();
    }
    return res;
}

//
// Created by Daniel Sanchez on 7/11/25.
//

#include "StreamerPago.h"

#include "GestorStreamers.h"
#include "Utils.h"

StreamerPago::StreamerPago() {
    fecha_inicio_plan = 0;
    cantidad_metricas_basicas = 0;
    metricas_basicas = nullptr;
    cantidad_metricas_calidad = 0;
    metricas_calidad = nullptr;
    cantidad_metricas_engagement = 0;
    metricas_engagement = nullptr;
}

StreamerPago::~StreamerPago() {
    delete[] metricas_basicas;
    delete[] metricas_calidad;
    delete[] metricas_engagement;
}

StreamerPago &StreamerPago::operator=(const StreamerPago &other) {
    if (&other == this) {
        return *this;
    }
    Streamer::operator=(other);
    set_fecha_inicio_plan(other.fecha_inicio_plan);
    // Metricas básicas
    set_cantidad_metricas_basicas(other.cantidad_metricas_basicas);
    for (int i = 0; i < other.cantidad_metricas_basicas; i++) {
        metricas_basicas[i] = other.metricas_basicas[i];
    }
    // Metricas calidad
    set_cantidad_metricas_calidad(other.cantidad_metricas_calidad);
    for (int i = 0; i < other.cantidad_metricas_calidad; i++) {
        metricas_calidad[i] = other.metricas_calidad[i];
    }
    // Metricas engagement
    set_cantidad_metricas_engagement(other.cantidad_metricas_engagement);
    for (int i = 0; i < other.cantidad_metricas_engagement; i++) {
        metricas_engagement[i] = other.metricas_engagement[i];
    }
    return *this;
}

int StreamerPago::get_fecha_inicio_plan() const {
    return fecha_inicio_plan;
}

void StreamerPago::set_fecha_inicio_plan(int n) {
    fecha_inicio_plan = n;
}

int StreamerPago::get_cantidad_metricas_basicas() const {
    return cantidad_metricas_basicas;
}

void StreamerPago::set_cantidad_metricas_basicas(int n) {
    cantidad_metricas_basicas = n;
}

int StreamerPago::get_cantidad_metricas_calidad() const {
    return cantidad_metricas_calidad;
}

void StreamerPago::set_cantidad_metricas_calidad(int n) {
    cantidad_metricas_calidad = n;
}

int StreamerPago::get_cantidad_metricas_engagement() const {
    return cantidad_metricas_engagement;
}

void StreamerPago::set_cantidad_metricas_engagement(int n) {
    cantidad_metricas_engagement = n;
}

void StreamerPago::leer(std::ifstream &arch) {
    Streamer::leer(arch);
    fecha_inicio_plan = leer_fecha(arch);
    arch >> std::ws;
}

void StreamerPago::imprimir(std::ostream &arch) {
    imprimir_sep(arch, 80, '=');
    arch << std::setw(50) << std::right << "REPORTE DE STREAMERS" << std::endl;
    imprimir_sep(arch, 80, '=');

    Streamer::imprimir(arch);
    arch << "TIPO: StreamerPago" << std::endl;
    imprimir_sep(arch, 80, '-');

    // Metrica basicas
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
        imprimir_sep(arch, 80, '-');
    }

    // Metrica engagement
    if (cantidad_metricas_engagement > 0) {
        arch << std::setprecision(2) << std::fixed;
        arch << "[ENGAGE] CHAT_MSGS: " << std::setw(6) << get_chat_msgs() << " | ";
        arch << "CHATTERS_UNICOS: " << std::setw(6) << get_chatters_unicos() << " | ";
        arch << "CLIPS: " << std::setw(4) << get_clips() << " | ";
        arch << "ACTIVAS: " << get_metricas_engagement_activas() << " | ";
        arch << "EXPIRADAS: " << get_metricas_engagement_expiradas() << std::endl;
        arch << "  Código    Fecha Calc.    Expira    Estado   Msgs   Chatters   Clips   Descripción" << std::endl;
        for (int i = 0; i < cantidad_metricas_engagement; i++) {
            arch << "  ";
            metricas_engagement[i].imprimir(arch);
        }
        imprimir_sep(arch, 80, '-');
    }

    // Metrica calidad
    if (cantidad_metricas_calidad > 0) {
        arch << std::setprecision(2) << std::fixed;
        arch << "[QUALITY] BITRATE_PROM: " << std::setw(4) << get_bitrate_prom() << "kbps | ";
        arch << "DROP%_PROM: " << std::setw(4) << get_drop_prom() << " | ";
        arch << "FPS_PROM: " << std::setw(3) << get_fps_prom() << " | ";
        arch << "ACTIVAS: " << get_metricas_calidad_activas() << " | ";
        arch << "EXPIRADAS: " << get_metricas_calidad_expiradas() << std::endl;
        arch << "  Código    Fecha Calc.    Expira    Estado   Bitrate   Drop%   FPS   Descripción" << std::endl;
        for (int i = 0; i < cantidad_metricas_calidad; i++) {
            arch << "  ";
            metricas_calidad[i].imprimir(arch);
        }
        imprimir_sep(arch, 80, '-');
    }

    arch << "[TOTAL] MÉTRICAS ACTIVAS: " << get_metricas_activas() << " | ";
    arch << "MÉTRICAS EXPIRADAS: " << get_metricas_expiradas() << " | ";
    arch << "FECHA DE REPORTE: ";
    imprimir_fecha(arch, FECHA_REPORTE) << std::endl;
    imprimir_sep(arch, 80, '=');
}

int StreamerPago::get_metricas_basicas_activas() const {
    int res = 0;
    for (int i = 0; i < cantidad_metricas_basicas; i++) {
        res += (metricas_basicas[i].get_estado()) ? 1 : 0;
    }
    return res;
}

int StreamerPago::get_metricas_calidad_activas() const {
    int res = 0;
    for (int i = 0; i < cantidad_metricas_calidad; i++) {
        res += (metricas_calidad[i].get_estado()) ? 1 : 0;
    }
    return res;
}

int StreamerPago::get_metricas_engagement_activas() const {
    int res = 0;
    for (int i = 0; i < cantidad_metricas_engagement; i++) {
        res += (metricas_engagement[i].get_estado()) ? 1 : 0;
    }
    return res;
}

int StreamerPago::get_metricas_activas() const {
    return get_metricas_basicas_activas() + get_metricas_calidad_activas() + get_metricas_engagement_activas();
}

int StreamerPago::get_metricas_basicas_expiradas() const {
    int res = 0;
    for (int i = 0; i < cantidad_metricas_basicas; i++) {
        res += (metricas_basicas[i].get_estado()) ? 0 : 1;
    }
    return res;
}

int StreamerPago::get_metricas_calidad_expiradas() const {
    int res = 0;
    for (int i = 0; i < cantidad_metricas_calidad; i++) {
        res += (metricas_calidad[i].get_estado()) ? 0 : 1;
    }
    return res;
}

int StreamerPago::get_metricas_engagement_expiradas() const {
    int res = 0;
    for (int i = 0; i < cantidad_metricas_engagement; i++) {
        res += (metricas_engagement[i].get_estado()) ? 0 : 1;
    }
    return res;
}

int StreamerPago::get_metricas_expiradas() const {
    return get_metricas_basicas_expiradas() + get_metricas_calidad_expiradas() + get_metricas_engagement_expiradas();
}

double StreamerPago::get_horas_transmitidas() const {
    double res = 0;
    for (int i = 0; i < cantidad_metricas_basicas; i++) {
        res += metricas_basicas[i].get_horas_transmitidas();
    }
    return res;
}

int StreamerPago::get_viewers_prom() const {
    int res = 0;
    for (int i = 0; i < cantidad_metricas_basicas; i++) {
        res += metricas_basicas[i].get_espectadores_promedio();
    }
    return res;
}

int StreamerPago::get_chat_msgs() const {
    int res = 0;
    for (int i = 0; i < cantidad_metricas_engagement; i++) {
        res += metricas_engagement[i].get_mensajes_chat();
    }
    return res;
}

int StreamerPago::get_chatters_unicos() const {
    int res = 0;
    for (int i = 0; i < cantidad_metricas_engagement; i++) {
        res += metricas_engagement[i].get_usuarios_unicos_chat();
    }
    return res;
}

int StreamerPago::get_clips() const {
    int res = 0;
    for (int i = 0; i < cantidad_metricas_engagement; i++) {
        res += metricas_engagement[i].get_clips_generados();
    }
    return res;
}

int StreamerPago::get_bitrate_prom() const {
    int res = 0;
    for (int i = 0; i < cantidad_metricas_calidad; i++) {
        res += metricas_calidad[i].get_bitrate_promedio_kbps();
    }
    return res;
}

double StreamerPago::get_drop_prom() const {
    double res = 0;
    for (int i = 0; i < cantidad_metricas_calidad; i++) {
        res += metricas_calidad[i].get_porcentaje_frames_perdidos();
    }
    return res;
}

int StreamerPago::get_fps_prom() const {
    int res = 0;
    for (int i = 0; i < cantidad_metricas_calidad; i++) {
        res += metricas_calidad[i].get_fps_promedio();
    }
    return res;
}

void StreamerPago::leer_metrica_basica(std::ifstream &arch) {
    if (metricas_basicas == nullptr) {
        metricas_basicas = new MetricaBasica[MAX_METRICS_COUNT]{};
    }
    metricas_basicas[cantidad_metricas_basicas].leer(arch);
    cantidad_metricas_basicas++;
}

void StreamerPago::leer_metrica_calidad(std::ifstream &arch) {
    if (metricas_calidad == nullptr) {
        metricas_calidad = new MetricaCalidad[MAX_METRICS_COUNT]{};
    }
    metricas_calidad[cantidad_metricas_calidad].leer(arch);
    cantidad_metricas_calidad++;
}

void StreamerPago::leer_metrica_engagement(std::ifstream &arch) {
    if (metricas_engagement == nullptr) {
        metricas_engagement = new MetricaEngagement[MAX_METRICS_COUNT]{};
    }
    metricas_engagement[cantidad_metricas_engagement].leer(arch);
    cantidad_metricas_engagement++;
}

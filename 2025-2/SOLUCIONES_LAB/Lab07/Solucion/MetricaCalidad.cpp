//
// Created by Daniel Sanchez on 7/11/25.
//

#include "MetricaCalidad.h"

#include "Metrica.h"

#include <fstream>

#include "Metrica.h"

MetricaCalidad::MetricaCalidad() {
    bitrate_promedio_kbps = 0;
    porcentaje_frames_perdidos = 0.0;
    fps_promedio = 0;
}

MetricaCalidad &MetricaCalidad::operator=(const MetricaCalidad &m) {
    if (this == &m) {
        return *this;
    }
    Metrica::operator=(m);
    set_bitrate_promedio_kbps(m.bitrate_promedio_kbps);
    set_porcentaje_frames_perdidos(m.porcentaje_frames_perdidos);
    set_fps_promedio(m.fps_promedio);
    return *this;
}

int MetricaCalidad::get_bitrate_promedio_kbps() const {
    return bitrate_promedio_kbps;
}

void MetricaCalidad::set_bitrate_promedio_kbps(int x) {
    bitrate_promedio_kbps = x;
}

double MetricaCalidad::get_porcentaje_frames_perdidos() const {
    return porcentaje_frames_perdidos;
}

void MetricaCalidad::set_porcentaje_frames_perdidos(double x) {
    porcentaje_frames_perdidos = x;
}

int MetricaCalidad::get_fps_promedio() const {
    return fps_promedio;
}

void MetricaCalidad::set_fps_promedio(int x) {
    fps_promedio = x;
}

void MetricaCalidad::leer(std::ifstream &arch) {
    Metrica::leer(arch);
    char c;
    arch >> bitrate_promedio_kbps >> c >> porcentaje_frames_perdidos >> c >> fps_promedio;
    arch >> std::ws;
}

std::ostream & MetricaCalidad::imprimir(std::ostream &arch) const {
    Metrica::imprimir(arch);
    arch << std::setprecision(2) << std::fixed << std::setfill(' ');
    arch << std::setw(4) << std::right << bitrate_promedio_kbps << "     ";
    arch << porcentaje_frames_perdidos << "    ";
    arch << fps_promedio << "  ";
    char desc[32];
    get_descripcion(desc);
    arch << std::setw(18) << std::right << desc;
    arch << std::endl;
    return arch;
}

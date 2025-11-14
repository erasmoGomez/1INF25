//
// Created by Daniel Sanchez on 7/11/25.
//

#include "MetricaBasica.h"

#include "Metrica.h"

#include <fstream>

MetricaBasica::MetricaBasica() {
    horas_transmitidas = 0.0;
    espectadores_promedio = 0;
}

MetricaBasica &MetricaBasica::operator=(const MetricaBasica &m) {
    if (this == &m) {
        return *this;
    }
    Metrica::operator=(m);
    set_horas_transmitidas(m.horas_transmitidas);
    set_espectadores_promedio(m.espectadores_promedio);
    return *this;
}

double MetricaBasica::get_horas_transmitidas() const {
    return horas_transmitidas;
}

void MetricaBasica::set_horas_transmitidas(double x) {
    horas_transmitidas = x;
}

int MetricaBasica::get_espectadores_promedio() const {
    return espectadores_promedio;
}

void MetricaBasica::set_espectadores_promedio(int x) {
    espectadores_promedio = x;
}

void MetricaBasica::leer(std::ifstream &arch) {
    Metrica::leer(arch);
    char c;
    arch >> horas_transmitidas >> c >> espectadores_promedio;
    arch >> std::ws;
}

std::ostream & MetricaBasica::imprimir(std::ostream &arch) const {
    Metrica::imprimir(arch);
    arch << std::setprecision(2) << std::fixed << std::setfill(' ');
    arch << std::setw(4) << std::right << horas_transmitidas << "      ";
    arch << espectadores_promedio << "m ";
    char desc[32];
    get_descripcion(desc);
    arch << std::setw(18) << std::right << desc;
    arch << std::endl;
    return arch;
}

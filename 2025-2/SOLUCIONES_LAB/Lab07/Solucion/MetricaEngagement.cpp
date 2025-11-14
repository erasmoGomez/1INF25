//
// Created by Daniel Sanchez on 7/11/25.
//

#include "MetricaEngagement.h"

#include "Metrica.h"

#include <fstream>

MetricaEngagement::MetricaEngagement() {
    mensajes_chat = 0;
    usuarios_unicos_chat = 0;
    clips_generados = 0;
}

MetricaEngagement &MetricaEngagement::operator=(const MetricaEngagement &other) {
    if (this == &other)
        return *this;
    Metrica::operator=(other);
    set_mensajes_chat(other.mensajes_chat);
    set_usuarios_unicos_chat(other.usuarios_unicos_chat);
    set_clips_generados(other.clips_generados);
    return *this;
}

int MetricaEngagement::get_mensajes_chat() {
    return mensajes_chat;
}

void MetricaEngagement::set_mensajes_chat(int n) {
    mensajes_chat = n;
}

int MetricaEngagement::get_usuarios_unicos_chat() {
    return usuarios_unicos_chat;
}

void MetricaEngagement::set_usuarios_unicos_chat(int n) {
    usuarios_unicos_chat = n;
}

int MetricaEngagement::get_clips_generados() {
    return clips_generados;
}

void MetricaEngagement::set_clips_generados(int n) {
    clips_generados = n;
}

void MetricaEngagement::leer(std::ifstream &arch) {
    Metrica::leer(arch);
    char c;
    arch >> mensajes_chat >> c >> usuarios_unicos_chat >> c >> clips_generados;
    arch >> std::ws;
}

std::ostream &MetricaEngagement::imprimir(std::ostream &arch) const {
    Metrica::imprimir(arch);
    arch << std::setprecision(2) << std::fixed << std::setfill(' ');
    arch << std::setw(4) << std::right << mensajes_chat << "     ";
    arch << usuarios_unicos_chat << "      ";
    arch << clips_generados << "  ";
    char desc[32];
    get_descripcion(desc);
    arch << std::setw(18) << std::right << desc;
    arch << std::endl;
    return arch;
}

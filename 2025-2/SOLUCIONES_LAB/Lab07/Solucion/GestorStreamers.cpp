//
// Created by Daniel Sanchez on 7/11/25.
//

#include "GestorStreamers.h"

#include "StreamerGratuito.h"
#include "StreamerPago.h"
#include "Utils.h"

#include <cstring>
#include <fstream>
#include <iostream>

GestorStreamers::GestorStreamers() {
    cantidad_gratuitos = 0;
    cantidad_pagados = 0;
    streamers_gratuitos = nullptr;
    streamers_pagados = nullptr;
}

GestorStreamers::~GestorStreamers() {
    delete[] streamers_gratuitos;
    delete[] streamers_pagados;
}

void GestorStreamers::cargar_datos_streamers(const char *arch_nom) {
    std::ifstream arch(arch_nom);
    if (not arch.is_open()) {
        std::cerr << "Error al abrir el archivo " << arch_nom << std::endl;
        exit(1);
    }
    StreamerGratuito *streamers_gratuitos_buf = new StreamerGratuito[100]{};
    StreamerPago *streamers_pagados_buf = new StreamerPago[100]{};
    while (true) {
        char tipo[16];
        arch.getline(tipo, 16, ',');
        if (arch.eof()) {
            break;
        }
        if (strcmp(tipo, "Gratuito") == 0) {
            streamers_gratuitos_buf[cantidad_gratuitos].leer(arch);
            cantidad_gratuitos++;
        } else {
            streamers_pagados_buf[cantidad_pagados].leer(arch);
            cantidad_pagados++;
        }
    }
    streamers_gratuitos = new StreamerGratuito[cantidad_gratuitos]{};
    for (int i = 0; i < cantidad_gratuitos; i++) {
        streamers_gratuitos[i] = streamers_gratuitos_buf[i];
    }
    delete[] streamers_gratuitos_buf;
    streamers_pagados = new StreamerPago[cantidad_pagados]{};
    for (int i = 0; i < cantidad_pagados; i++) {
        streamers_pagados[i] = streamers_pagados_buf[i];
    }
    delete[] streamers_pagados_buf;

    arch.close();
}

void GestorStreamers::actualizar_datos_metricas(const char *arch_nom) {
    std::ifstream arch(arch_nom);
    if (not arch.is_open()) {
        std::cerr << "Error al abrir el archivo " << arch_nom << std::endl;
        exit(1);
    }

    while (true) {
        char tipo[16], c;
        arch.getline(tipo, 16, ',');
        if (arch.eof()) {
            break;
        }
        int streamer_id;
        arch >> streamer_id >> c;
        agregar_metrica_streamer(streamer_id, tipo, arch);
    }

    arch.close();
}

void GestorStreamers::generar_reportes() const {
    for (int i = 0; i < cantidad_gratuitos; i++) {
        StreamerGratuito &gratuito = streamers_gratuitos[i];
        char cuenta[24];
        char categoria[24];
        gratuito.get_cuenta(cuenta);
        gratuito.get_categoria(categoria);
        const char *arch_nom = generar_nombre_reporte("Gratuito", cuenta, categoria);
        std::ofstream arch(arch_nom);
        if (not arch.is_open()) {
            std::cerr << "Error al abrir el archivo " << arch_nom << std::endl;
            exit(1);
        }
        gratuito.imprimir(arch);
        arch.close();
    }
    for (int i = 0; i < cantidad_pagados; i++) {
        StreamerPago &pagado = streamers_pagados[i];
        char cuenta[24];
        char categoria[24];
        pagado.get_cuenta(cuenta);
        pagado.get_categoria(categoria);
        const char *arch_nom = generar_nombre_reporte("Pagado", cuenta, categoria);
        std::ofstream arch(arch_nom);
        if (not arch.is_open()) {
            std::cerr << "Error al abrir el archivo " << arch_nom << std::endl;
            exit(1);
        }
        pagado.imprimir(arch);
        arch.close();
    }
}

void GestorStreamers::agregar_metrica_streamer(int streamer_id, const char *tipo, std::ifstream &arch) {
    for (int i = 0; i < cantidad_gratuitos; i++) {
        if (streamers_gratuitos[i].get_id() == streamer_id) {
            streamers_gratuitos[i].leer_metrica_basica(arch);
            return;
        }
    }
    for (int i = 0; i < cantidad_pagados; i++) {
        if (streamers_pagados[i].get_id() == streamer_id) {
            if (strcmp(tipo, "BASIC") == 0) {
                streamers_pagados[i].leer_metrica_basica(arch);
            } else if (strcmp(tipo, "QUALITY") == 0) {
                streamers_pagados[i].leer_metrica_calidad(arch);
            } else if (strcmp(tipo, "ENGAGEMENT") == 0) {
                streamers_pagados[i].leer_metrica_engagement(arch);
            } else {
                std::cerr << "Tipo de metrica no reconocida: " << tipo << std::endl;
                exit(1);
            }
        }
    }
}

char *GestorStreamers::generar_nombre_reporte(const char *tipo_stream, const char *cuenta, const char *categoria) {
    char res[256];
    strcpy(res, "Reportes/");
    strcat(res, tipo_stream);
    strcat(res, "/");
    strcat(res, cuenta);
    strcat(res, "_");
    strcat(res, categoria);
    strcat(res, "_");
    strcat(res, "2025-11-07");
    strcat(res, ".txt");
    return my_strdup(res);
}

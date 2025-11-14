//
// Created by Daniel Sanchez on 1/10/25.
//

#include "PunterosGenericos.h"

#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>

bool leer_streamer(std::ifstream &arch, void *&streamer) {
    constexpr int BUF_SIZE = 128;
    char buffer1[BUF_SIZE];
    char buffer2[BUF_SIZE];
    long long tiempo_total;
    long promedio_espectadores;
    long seguidores;
    char c;

    arch.getline(buffer1, BUF_SIZE, ',');
    if (arch.eof()) {
        return false;
    }
    arch >> tiempo_total >> c >> promedio_espectadores >> c >> seguidores;
    arch.getline(buffer2, BUF_SIZE, '\n');

    void **streamer_arr = new void *[4];
    streamer_arr[0] = strdup(buffer1);
    streamer_arr[1] = new long(seguidores);
    streamer_arr[2] = strdup(buffer2);
    streamer_arr[3] = nullptr;

    streamer = (void *) streamer_arr;
    return true;
}

void cargastreamers(void *&streamers) {
    std::ifstream arch;
    const char *filename = "Data/streamers.csv";
    arch.open(filename, std::ios::in);
    if (not arch.is_open()) {
        std::cerr << "Error while opening file " << filename << std::endl;
        exit(1);
    }
    int n = 0;
    void *streamers_aux[300];
    while (true) {
        if (not leer_streamer(arch, streamers_aux[n])) {
            break;
        }
        n += 1;
    }
    void **streamers_arr = new void *[n + 1]{};
    for (int i = 0; i < n; i += 1) {
        streamers_arr[i] = streamers_aux[i];
    }
    streamers_arr[n] = nullptr;
    streamers = (void *) streamers_arr;
    arch.close();
}

bool leer_comentario(std::ifstream &arch, void *&comentario) {
    constexpr int BUF_SIZE = 256;
    char codigo_buff[9];
    char texto_buff[256];
    char emisor_buff[32];
    char receptor_buff[32];

    arch.getline(codigo_buff, 9, ',');
    if (arch.eof()) {
        return false;
    }
    arch.getline(texto_buff, 256, '[');
    arch.getline(emisor_buff, 32, ' ');
    arch.getline(receptor_buff, 32, ']');

    char dummy[10];
    arch.getline(dummy, 10, '\n');
    arch >> std::ws;

    void **comentario_arr = new void *[4]{};
    comentario_arr[0] = strdup(codigo_buff);
    comentario_arr[1] = strdup(emisor_buff);
    comentario_arr[2] = strdup(receptor_buff);
    comentario_arr[3] = strdup(texto_buff);
    comentario = (void *) comentario_arr;
    return true;
}

void cargacomentarios(void *&comentarios) {
    std::ifstream arch;
    const char *filename = "Data/comentarios.csv";
    arch.open(filename, std::ios::in);
    if (not arch.is_open()) {
        std::cerr << "Error while opening file " << filename << std::endl;
        exit(1);
    }
    void *comentarios_aux[200]{};
    int n = 0;
    while (true) {
        if (not leer_comentario(arch, comentarios_aux[n])) {
            break;
        }
        n += 1;
    }
    void **comentarios_arr = new void *[n + 1]{};
    for (int i = 0; i < n; i += 1) {
        comentarios_arr[i] = comentarios_aux[i];
    }
    comentarios_arr[n] = nullptr;
    comentarios = (void *) comentarios_arr;
    arch.close();
}

void *buscar_comentario(void **comentarios, char *cuenta) {
    for (int i = 0; comentarios[i] != nullptr; i += 1) {
        void **comentario = (void **) comentarios[i];
        char *emisor = (char *) comentario[1];
        if (strcmp(emisor, cuenta) == 0) {
            return comentario;
        }
    }
    return nullptr;
}

void incrementar_memoria(void **&streamer_comentarios, int &cap, int &n) {
    cap += 5;
    if (streamer_comentarios == nullptr) {
        streamer_comentarios = new void *[cap]{};
        n = 0;
    } else {
        void **streamer_comentarios_new = new void *[cap]{};
        for (int i = 0; i < n; i += 1) {
            streamer_comentarios_new[i] = streamer_comentarios[i];
        }
        streamer_comentarios_new[n + 1] = nullptr;
        delete[] streamer_comentarios;
        streamer_comentarios = streamer_comentarios_new;
    }
}

void agreagar_comentario(void *&streamer_comentarios, void *comentario, int &cap, int &n) {
    void **comentario_arr = (void **) comentario;
    char *receptor = (char *) comentario_arr[2];
    char *texto = (char *) comentario_arr[3];
    void **streamer_comentario = new void *[2]{};
    streamer_comentario[0] = strdup(receptor);
    streamer_comentario[1] = strdup(texto);

    void **streamer_comentarios_arr = (void **) streamer_comentarios;
    if (n == cap) {
        incrementar_memoria(streamer_comentarios_arr, cap, n);
    }
    streamer_comentarios_arr[n] = (void *) streamer_comentario;
    n += 1;
    streamer_comentarios_arr[n] = nullptr;
    streamer_comentarios = (void *)streamer_comentarios_arr;
}

void actualizacomentarios(void *streamers, void *comentarios) {
    void **streamers_arr = (void **) streamers;
    void **comentarios_arr = (void **) comentarios;
    int tamaños[300]{};
    int capacidades[300]{};
    for (int i = 0; streamers_arr[i] != nullptr; i += 1) {
        void **streamer = (void **) streamers_arr[i];
        char *cuenta = (char *) streamer[0];
        void *comentario = buscar_comentario(comentarios_arr, cuenta);
        if (comentario == nullptr) {
            continue;
        }
        agreagar_comentario(streamer[3], comentario, capacidades[i], tamaños[i]);
    }
}

void imprimestreamers(void *streamers) {
    std::ofstream arch;
    const char *filename = "reporte.txt";
    arch.open(filename, std::ios::out);
    if (not arch.is_open()) {
        std::cerr << "Error while opening file " << filename << std::endl;
        exit(1);
    }
    void **streamers_arr = (void **) streamers;
    for (int i = 0; streamers_arr[i] != nullptr; i += 1) {
        void **streamer = (void **) streamers_arr[i];
        char *cuenta = (char *) streamer[0];
        long *seguidores_ptr = (long *) streamer[1];
        void **comentarios = (void **) streamer[3];
        arch << std::setw(80) << std::setfill('=') << '\n';
        arch << "Cuenta           Seguidores" << std::endl;
        arch << std::setfill(' ');
        arch << std::left << cuenta;
        arch << std::setw(20) << std::right << *seguidores_ptr << std::endl;
        arch << std::setw(80) << std::setfill('-') << '\n';
        if (comentarios == nullptr) {
            continue;
        }
        arch << "Comentarios emitidos:" << std::endl;
        arch << std::setw(80) << std::setfill('-') << '\n';
        arch << "Receptor           Texto" << std::endl;
        arch << std::setw(80) << std::setfill('-') << '\n';
        for (int j = 0; comentarios[j] != nullptr; j += 1) {
            void **comentario = (void **) comentarios[j];
            char *receptor = (char *) comentario[0];
            char *texto = (char *) comentario[1];
            arch << std::setfill(' ');
            arch << std::left << std::setw(24) << receptor;
            arch << std::right << std::setw(48) << texto << std::endl;
        }
    }
}

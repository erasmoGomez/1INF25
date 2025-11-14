//
// Created by Daniel Sanchez on 17/09/25.
//

#include "StreamingTools.h"

#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>

char *cstring_duplicate(char *cstr) {
    char *dup = new char[strlen(cstr) + 1];
    strcpy(dup, cstr);
    return dup;
}

char *categoria_leer_codigo(std::ifstream &arch, const char sep = ',') {
    constexpr int BUF_SIZE = 7;
    char buffer[BUF_SIZE];
    arch.getline(buffer, BUF_SIZE, sep);
    if (arch.eof()) {
        return nullptr;
    }
    return cstring_duplicate(buffer);
}

char *categoria_leer_nombre(std::ifstream &arch) {
    constexpr int BUF_SIZE = 60;
    char buffer[BUF_SIZE];
    arch.getline(buffer, BUF_SIZE, ',');
    return cstring_duplicate(buffer);
}

char *categoria_leer_descripcion(std::ifstream &arch) {
    constexpr int BUF_SIZE = 120;
    char buffer[BUF_SIZE];
    arch.getline(buffer, BUF_SIZE);
    return cstring_duplicate(buffer);
}

void incrementar_espacio(int &cap, int &n, char ***&categorias) {
    cap += MEM_INC;
    char ***new_categorias = new char **[cap + 1]{};
    for (int i = 0; i < n; i += 1) {
        new_categorias[i] = categorias[i];
    }
    if (categorias != nullptr) {
        delete[] categorias;
    }
    categorias = new_categorias;
}

void incrementar_espacio(int &cap, int &n, char ***&comentarios, char ***&etiquetas) {
    cap += MEM_INC;
    char ***new_comentarios = new char **[cap + 1]{};
    char ***new_etiquetas = new char **[cap + 1]{};
    for (int i = 0; i < n; i += 1) {
        new_comentarios[i] = comentarios[i];
        new_etiquetas[i] = etiquetas[i];
    }
    delete[] comentarios;
    delete[] etiquetas;
    comentarios = new_comentarios;
    etiquetas = new_etiquetas;
}

void cargarCategorias(const char *arch_nom, char ***&categorias) {
    std::ifstream arch;
    arch.open(arch_nom, std::ios::in);
    if (not arch.is_open()) {
        std::cerr << "Error al abrir el archivo " << arch_nom << std::endl;
        exit(1);
    }
    int cap = 0;
    int n = 0;
    categorias = nullptr;
    while (true) {
        if (n == cap) {
            incrementar_espacio(cap, n, categorias);
        }
        char *codigo = categoria_leer_codigo(arch);
        if (codigo == nullptr) {
            categorias[n] = nullptr;
            break;
        }
        char *nombre = categoria_leer_nombre(arch);
        char *descripcion = categoria_leer_descripcion(arch);
        char **categoria = new char *[CAT_N];
        categoria[CAT_CODIGO] = codigo;
        categoria[CAT_NOMBRE] = nombre;
        categoria[CAT_DESCRIPCION] = descripcion;
        categorias[n] = categoria;
        n += 1;
    }
    arch.close();
}

void liberarCategorias(char ***&categorias) {
    for (int i = 0; categorias[i] != nullptr; i += 1) {
        char **categoria = categorias[i];
        delete[] categoria[CAT_CODIGO];
        delete[] categoria[CAT_NOMBRE];
        delete[] categoria[CAT_DESCRIPCION];
        delete[] categoria;
    }
    delete[] categorias;
    categorias = nullptr;
}

void incrementar_espacio(int &cap, int &n, char ***&streamers, int **&fechasPromedios,
                         long long **&tiempoRepSeguidores) {
    cap += MEM_INC;
    char ***new_streamers = new char **[cap + 1]{};
    int **new_fechasPromedios = new int *[cap + 1]{};
    long long **new_tiempoRepSeguidores = new long long *[cap + 1]{};
    for (int i = 0; i < n; i += 1) {
        new_streamers[i] = streamers[i];
        new_fechasPromedios[i] = fechasPromedios[i];
        new_tiempoRepSeguidores[i] = tiempoRepSeguidores[i];
    }
    if (streamers != nullptr) {
        delete[] streamers;
        delete[] fechasPromedios;
        delete[] tiempoRepSeguidores;
    }
    streamers = new_streamers;
    fechasPromedios = new_fechasPromedios;
    tiempoRepSeguidores = new_tiempoRepSeguidores;
}

char *streamer_leer_cuenta(std::ifstream &arch) {
    constexpr int BUF_SIZE = 60;
    char buffer[BUF_SIZE];
    arch.getline(buffer, BUF_SIZE, ',');
    if (arch.eof()) {
        return nullptr;
    }
    return cstring_duplicate(buffer);
}

int streamer_leer_fecha(std::ifstream &arch) {
    char c;
    int dia, mes, anho;
    arch >> dia >> c >> mes >> c >> anho >> c;
    return anho * 10000 + mes * 100 + dia;
}

long long streamer_leer_tiempo_reproducido(std::ifstream &arch) {
    char c;
    long long tiempo;
    arch >> tiempo >> c;
    return tiempo;
}

int streamer_leer_promedio_espectadores(std::ifstream &arch) {
    char c;
    int promedio;
    arch >> promedio >> c;
    return promedio;
}

long long streamer_leer_seguidores(std::ifstream &arch) {
    char c;
    long long seguidores;
    arch >> seguidores >> c;
    return seguidores;
}

void cargarStreamers(const char *arch_nom, char ***&streamers, int **&fechasPromedios,
                     long long **&tiempoRepSeguidores) {
    std::ifstream arch;
    arch.open(arch_nom, std::ios::in);
    if (not arch.is_open()) {
        std::cerr << "Error al abrir el archivo " << arch_nom << std::endl;
        exit(1);
    }
    streamers = nullptr;
    fechasPromedios = nullptr;
    tiempoRepSeguidores = nullptr;
    int cap = 0;
    int n = 0;
    while (true) {
        if (n == cap) {
            incrementar_espacio(cap, n, streamers, fechasPromedios, tiempoRepSeguidores);
        }
        char *cuenta = streamer_leer_cuenta(arch);
        if (cuenta == nullptr) {
            streamers[n] = nullptr;
            fechasPromedios[n] = nullptr;
            tiempoRepSeguidores[n] = nullptr;
            break;
        }
        int fecha_creacion = streamer_leer_fecha(arch);
        int fecha_destruccion = streamer_leer_fecha(arch);
        long long tiempo_rep = streamer_leer_tiempo_reproducido(arch);
        int promedio_espectadores = streamer_leer_promedio_espectadores(arch);
        long long seguidores = streamer_leer_seguidores(arch);
        char *cat_codigo = categoria_leer_codigo(arch, '\n');
        arch >> std::ws;

        char **streamer = new char *[STREAMER_N]{};
        streamer[STREAMER_CUENTA] = cuenta;
        streamer[STREAMER_CATEGORIA] = cat_codigo;

        int *fechas = new int [FECHA_N];
        fechas[FECHA_CREACION] = fecha_creacion;
        fechas[FECHA_ULTIMA_TRANSMISION] = fecha_destruccion;

        long long *tiempos = new long long[STATS_N]{};
        tiempos[TIEMPO_TOTAL] = tiempo_rep;
        tiempos[CANTIDAD_SEGUIDORES] = seguidores;

        streamers[n] = streamer;
        fechasPromedios[n] = fechas;
        tiempoRepSeguidores[n] = tiempos;
        n += 1;
    }
    arch.close();
}

void liberarStreamers(char ***&streamers, int **&fechasPromedios, long long **&tiemposRepSeguidores) {
    for (int i = 0; streamers[i] != nullptr; i += 1) {
        char **streamer = streamers[i];
        delete[] streamer[STREAMER_CUENTA];
        delete[] streamer[STREAMER_CATEGORIA];
    }
    delete[] streamers;
    delete[] fechasPromedios;
    delete[] tiemposRepSeguidores;
    streamers = nullptr;
    fechasPromedios = nullptr;
    tiemposRepSeguidores = nullptr;
}

char *comentario_leer_usuario(std::ifstream &arch) {
    constexpr int BUF_SIZE = 20;
    char buffer[BUF_SIZE];
    arch.getline(buffer, BUF_SIZE, ',');
    if (arch.eof()) {
        return nullptr;
    }
    return cstring_duplicate(buffer);
}

bool leer_etiqueta(std::ifstream &arch, char *&etiqueta) {
    constexpr int BUF_SIZE = 40;
    char buffer[BUF_SIZE];
    int n = 0;
    bool keep_going = true;
    while (true) {
        char p = arch.peek();
        if (p != ' ' and p != ']') {
            char c;
            arch.get(c);
            buffer[n] = c;
            n += 1;
        } else {
            keep_going = (p == ' ');
            buffer[n] = '\0';
            arch.get();
            break;
        }
    }
    etiqueta = cstring_duplicate(buffer);
    return keep_going;
}

void leer_etiquetas(std::ifstream &arch, char **&etiqueta) {
    constexpr int BUF_SIZE = 10;
    char *etiqueta_buff[BUF_SIZE]{};
    int n = 0;
    while (leer_etiqueta(arch, etiqueta_buff[n])) {
        n += 1;
    }
    etiqueta = new char *[n + 1]{};
    for (int i = 0; i < n; i += 1) {
        etiqueta[i] = etiqueta_buff[i];
    }
    etiqueta[n] = nullptr;
}

char *comentario_leer_texto(std::ifstream &arch, char **&etiqueta) {
    constexpr int BUF_SIZE = 100;
    char buffer1[BUF_SIZE];
    arch.getline(buffer1, BUF_SIZE, '[');
    leer_etiquetas(arch, etiqueta);
    char buffer2[BUF_SIZE];
    arch.getline(buffer2, BUF_SIZE, '\n');
    char *text = new char [strlen(buffer1) + strlen(buffer2) + 1];
    strcpy(text, buffer1);
    strcat(text, buffer2);
    return text;
}

void cargarComentarios(const char *arch_nom, char ***&comentarios, char ***&etiquetas) {
    std::ifstream arch;
    arch.open(arch_nom, std::ios::in);
    if (not arch.is_open()) {
        std::cerr << "Error al abrir el archivo " << arch_nom << std::endl;
        exit(1);
    }
    comentarios = nullptr;
    etiquetas = nullptr;
    int cap = 0;
    int n = 0;
    while (true) {
        if (n == cap) {
            incrementar_espacio(cap, n, comentarios, etiquetas);
        }
        char *usuario = comentario_leer_usuario(arch);
        if (usuario == nullptr) {
            comentarios[n] = nullptr;
            etiquetas[n] = nullptr;
            break;
        }
        char *texto = comentario_leer_texto(arch, etiquetas[n]);
        char **comentario = new char *[2]{};
        comentario[0] = usuario;
        comentario[1] = texto;

        comentarios[n] = comentario;
        n += 1;
    }
    arch.close();
}

void print_divider(std::ofstream &arch, int n, const char div = '=') {
    for (int i = 0; i < n; i += 1) {
        arch << div;
    }
    arch << std::endl;
}

void imprimir_fecha(std::ofstream &arch, int fecha, const int size = 16) {
    int anho = fecha / 10000;
    int mes = (fecha % 10000) / 100;
    int dia = fecha % 100;
    arch << std::setfill('0');
    arch << std::right << std::setw(2) << dia << '-' << std::setw(2) << mes << '-' << std::setw(4) << anho;
    arch << "           ";
    arch << std::setfill(' ');
}

void imprimir_tiempo_rep(std::ofstream &arch, long long tiempo_rep) {
    double tiempo_rep_sec = tiempo_rep / 1000;
    double tiempo_rep_dias = tiempo_rep_sec / (3600 * 24);
    arch << std::fixed << std::setprecision(2);
    arch << tiempo_rep_dias;
    arch << " (días)";
}

bool streamer_etiquetado(char *cuenta, char **etiqueta) {
    for (int i = 0; etiqueta[i] != nullptr; i += 1) {
        if (strcmp(etiqueta[i], cuenta) == 0) {
            return true;
        }
    }
    return false;
}

void imprimir_etiquetas(std::ofstream &arch, char *cuenta, char ***comentarios, char ***etiquetas) {
    for (int i = 0; etiquetas[i] != nullptr; i += 1) {
        if (streamer_etiquetado(cuenta, etiquetas[i])) {
            char **comentario = comentarios[i];
            char *usuario = comentario[0];
            char *texto = comentario[1];
            arch << std::setw(6) << std::right << '[' << usuario << ']' << " '" << texto << "' ";
        }
    }
}

void imprimir_streamer(std::ofstream &arch, char **streamer, int *fechas, long long *tiempos, char ***comentarios,
                       char ***etiquetas) {
    char *cuenta = streamer[STREAMER_CUENTA];
    arch << std::setw(20) << std::left << cuenta;
    imprimir_fecha(arch, fechas[FECHA_CREACION]);
    imprimir_fecha(arch, fechas[FECHA_ULTIMA_TRANSMISION]);
    imprimir_tiempo_rep(arch, tiempos[TIEMPO_TOTAL]);
    arch << std::setw(16) << std::right << tiempos[CANTIDAD_SEGUIDORES];
    imprimir_etiquetas(arch, cuenta, comentarios, etiquetas);
    arch << std::endl;
}

void imprimirReporte(const char *arch_nom, char ***categorias, char ***streamers, int **fechasPromedios,
                     long long **tiempoRepSeguidores, char ***comentarios, char ***etiquetas) {
    std::ofstream arch;
    arch.open(arch_nom, std::ios::out);
    if (not arch.is_open()) {
        std::cerr << "Error al abrir el archivo " << arch_nom << std::endl;
        exit(1);
    }
    for (int i = 0; categorias[i] != nullptr; i++) {
        char **categoria = categorias[i];
        char *cat_nombre = categoria[CAT_NOMBRE];
        arch << '/' << cat_nombre;
        arch << '/' << std::endl;
        arch <<
                "CUENTA              FECHA CREACION       FECHA ULT. STREAM.   TIEMPO REP.    CANT. SEGUID.        ETIQUETAS"
                <<
                std::endl;
        print_divider(arch, 120);
        for (int j = 0; streamers[j] != nullptr; j++) {
            char **streamer = streamers[j];
            int *fechas = fechasPromedios[j];
            long long *tiempos = tiempoRepSeguidores[j];
            if (strcmp(streamer[STREAMER_CATEGORIA], categoria[CAT_CODIGO]) == 0) {
                imprimir_streamer(arch, streamer, fechas, tiempos, comentarios, etiquetas);
            }
        }
        arch << std::endl;
    }
    arch.close();
}

//
// Created by Daniel Sanchez on 19/10/25.
//

#include "GestorStreamer.h"

#include "Streamer.h"

#include <cstdlib>
#include <fstream>
#include <iostream>

GestorStreamer::GestorStreamer() {
    data = nullptr;
    dataVista = nullptr;
    cantidad_datos = 0;
    cantidad_datos_vista = 0;
}

GestorStreamer::~GestorStreamer() {
    delete[] data;
    delete[] dataVista;
}

void GestorStreamer::cargar_datos() {
    std::ifstream archivo;
    archivo.open("streamers.csv", std::ios::in);
    if (not archivo.is_open()) {
        std::cerr << "Error al abrir el archivo streamers.csv" << std::endl;
        exit(1);
    }
    Streamer aux_data[205]{};
    while (aux_data[cantidad_datos].leer_streamer(archivo)) {
        cantidad_datos += 1;
    }
    data = new Streamer[cantidad_datos]{};
    for (int i = 0; i < cantidad_datos; i++) {
        data[i].copiar(aux_data[i]);
    }
}

const char *menu =
        "1) Cargar datos\n"
        "2) Mostrar Reporte\n"
        "    1) Reporte Top10 streamers por número de seguidores\n"
        "    2) Reporte Bottom10 streamers por tiempo total transmitido\n"
        "    3) Reporte Top5 categoría con mayor promedio de espectadores\n"
        "    4) Reporte de Categoría\n"
        "    5) Reporte de Influencia\n"
        "3) Generar Reporte\n"
        "    1) Reporte Top10 streamers por número de seguidores\n"
        "    2) Reporte Bottom10 streamers por tiempo total transmitido\n"
        "    3) Reporte Top5 categoría con mayor promedio de espectadores\n"
        "    4) Reporte de Categoría\n"
        "    5) Reporte de Influencia\n"
        "4) Generar todos los reportes\n"
        "5) Terminar\n";

void GestorStreamer::mostrar_menu() {
    bool run = true;
    while (run) {
        std::cout << menu << std::endl;
        char input1, input2;
        std::cin >> input1;
        switch (input1) {
            case '1': {
                cargar_datos();
                break;
            }
            case '2': {
                std::cin >> input2;
                mostrar_generar_reporte(input2, false);
                break;
            }
            case '3': {
                std::cin >> input2;
                mostrar_generar_reporte(input2, true);
                break;
            }
            case '4': {
                generar_reportes();
                break;
            }
            case '5': {
                run = false;
                break;
            }
            default: {
                std::cerr << "Opcion incorrecta." << std::endl;
                break;
            }
        }
    }
}

void GestorStreamer::copiar_datos() {
    delete[] dataVista;
    cantidad_datos_vista = cantidad_datos;
    dataVista = new Streamer[cantidad_datos_vista]{};
    for (int i = 0; i < cantidad_datos_vista; i += 1) {
        dataVista[i].copiar(data[i]);
    }
}

void GestorStreamer::cortar_datos(int n) {
    Streamer *aux_datos = new Streamer[n];
    for (int i = 0; i < n; i += 1) {
        aux_datos[i].copiar(dataVista[i]);
    }
    delete[] dataVista;
    cantidad_datos_vista = n;
    dataVista = aux_datos;
}

void GestorStreamer::mostrar_generar_reporte(char input, bool generar) {
    switch (input) {
        case '1': {
            reporte1(generar);
            break;
        }
        case '2': {
            reporte2(generar);
            break;
        }
        case '3': {
            reporte3(generar);
            break;
        }
        case '4': {
            reporte4(generar);
            break;
        }
        case '5': {
            reporte5(generar);
            break;
        }
        default: {
            std::cerr << input << " incorrecta." << std::endl;
            break;
        }
    }
}

void GestorStreamer::generar_reportes() {
    reporte1(true);
    reporte2(true);
    reporte3(true);
    reporte4(true);
    reporte5(true);
}

void separator(std::ostream &os) {
    for (int i = 0; i < 80; i++) {
        os << '=';
    }
    os << std::endl;
}

void GestorStreamer::mostrar_dataVista(std::ostream &os) {
    separator(os);
    os << "CUENTA          CATEGORIA            NRO SEG.  PROM. ESPEC.  TIEMPO" << std::endl;
    separator(os);
    for (int i = 0; i < cantidad_datos_vista; i += 1) {
        dataVista[i].mostrar_streamer(os);
    }
    separator(os);
}

void GestorStreamer::mostrar_generar_dataVista(bool generar, const char *filename) {
    if (!generar) {
        mostrar_dataVista(std::cout);
    } else {
        std::ofstream file;
        file.open(filename, std::ios::out);
        if (not file.is_open()) {
            std::cerr << "Error al abrir el archivo " << filename << std::endl;
            exit(1);
        }
        mostrar_dataVista(file);
        file.close();
    }
}

int reporte1Compare(const void *a, const void *b) {
    Streamer *a1 = (Streamer *) a;
    Streamer *b1 = (Streamer *) b;
    return b1->get_n_seguidores() - a1->get_n_seguidores();
}

void GestorStreamer::reporte1(bool generar) {
    copiar_datos();
    qsort(dataVista, cantidad_datos_vista, sizeof(Streamer), reporte1Compare);
    cortar_datos(10);
    mostrar_generar_dataVista(generar, "Reporte1.txt");
}

int reporte2Compare(const void *a, const void *b) {
    Streamer *a1 = (Streamer *) a;
    Streamer *b1 = (Streamer *) b;
    long long res = a1->get_tiempo_total() - b1->get_tiempo_total();
    return (res > 0) ? 1 : -1;
}

void GestorStreamer::reporte2(bool generar) {
    copiar_datos();
    qsort(dataVista, cantidad_datos_vista, sizeof(Streamer), reporte2Compare);
    cortar_datos(10);
    mostrar_generar_dataVista(generar, "Reporte2.txt");
}

int reporte3Compare(const void *a, const void *b) {
    Streamer *a1 = (Streamer *) a;
    Streamer *b1 = (Streamer *) b;
    return b1->get_promedio_espectadores() - a1->get_promedio_espectadores();
}

void GestorStreamer::reporte3(bool generar) {
    copiar_datos();
    qsort(dataVista, cantidad_datos_vista, sizeof(Streamer), reporte3Compare);
    cortar_datos(5);
    mostrar_generar_dataVista(generar, "Reporte3.txt");
}

int reporte4Compare(const void *a, const void *b) {
    Streamer *a1 = (Streamer *) a;
    Streamer *b1 = (Streamer *) b;
    char buffer1[32], buffer2[32];
    a1->get_categoria(buffer1);
    b1->get_categoria(buffer2);
    return strcmp(buffer1, buffer2);
}

void GestorStreamer::reporte4(bool generar) {
    copiar_datos();
    qsort(dataVista, cantidad_datos_vista, sizeof(Streamer), reporte4Compare);
    mostrar_generar_dataVista(generar, "Reporte4.txt");
}

float get_influencia(Streamer *s) {
    float inf = (s->get_promedio_espectadores() * s->get_tiempo_total());
    return inf / log(s->get_tiempo_total() + 1);
}

int reporte5Compare(const void *a, const void *b) {
    Streamer *a1 = (Streamer *) a;
    Streamer *b1 = (Streamer *) b;
    float inf1 = get_influencia(a1);
    float inf2 = get_influencia(b1);
    return inf2 < inf1;
}

void GestorStreamer::reporte5(bool generar) {
    copiar_datos();
    qsort(dataVista, cantidad_datos_vista, sizeof(Streamer), reporte5Compare);
    mostrar_generar_dataVista(generar, "Reporte5.txt");
}

//
// Created by Daniel Sanchez on 19/10/25.
//

#ifndef SOLUCION_GESTORSTREAMER_H
#define SOLUCION_GESTORSTREAMER_H

#include "Streamer.h"

class GestorStreamer {
public:
    GestorStreamer();

    ~GestorStreamer();

    void cargar_datos();

    void mostrar_menu();

    void copiar_datos();

    void cortar_datos(int n);

    void mostrar_dataVista(std::ostream &os);

    void mostrar_generar_dataVista(bool generar, const char *filename);

    void mostrar_generar_reporte(char input, bool generar);

    void generar_reportes();

    void reporte1(bool generar);

    void reporte2(bool generar);

    void reporte3(bool generar);

    void reporte4(bool generar);

    void reporte5(bool generar);

private:
    Streamer *data;
    Streamer *dataVista;
    int cantidad_datos;
    int cantidad_datos_vista;
};


#endif //SOLUCION_GESTORSTREAMER_H

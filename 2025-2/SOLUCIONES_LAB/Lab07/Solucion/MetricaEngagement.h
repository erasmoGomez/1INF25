//
// Created by Daniel Sanchez on 7/11/25.
//

#ifndef SOLUCION_METRICAENGAGEMENT_H
#define SOLUCION_METRICAENGAGEMENT_H

#include "Metrica.h"

#include <fstream>

class MetricaEngagement : public Metrica {
private:
    int mensajes_chat;
    int usuarios_unicos_chat;
    int clips_generados;

public:
    MetricaEngagement();

    MetricaEngagement &operator=(const MetricaEngagement &other);

    int get_mensajes_chat();

    void set_mensajes_chat(int n);

    int get_usuarios_unicos_chat();

    void set_usuarios_unicos_chat(int n);

    int get_clips_generados();

    void set_clips_generados(int n);

    void leer(std::ifstream &arch);

    std::ostream &imprimir(std::ostream &arch) const;
};

#endif //SOLUCION_METRICAENGAGEMENT_H
